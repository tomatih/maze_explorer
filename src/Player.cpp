#include <Player.h>
#include <ScreenManager.h>

#include <raymath.h>
#include <math.h>

void Player::update_position(){
	// init travel vector
	Vector3 travel_distance = {0.0f, 0.0f, 0.0f};
	// get player input
	if(IsKeyDown(KEY_W)){
		travel_distance.z += 1.0f;
	}
	if(IsKeyDown(KEY_S)){
		travel_distance.z -= 1.0f;
	}
	if(IsKeyDown(KEY_D)){
		travel_distance.x -= 1.0f;
	}
	if(IsKeyDown(KEY_A)){
		travel_distance.x += 1.0f;
	}
	// rotate to move where looking
	travel_distance = Vector3RotateByAxisAngle(travel_distance, camera.up, rotation);
	// account for diagonal movement
	travel_distance = Vector3Normalize(travel_distance);
	// scale by speed (framerate independent)
	travel_distance = Vector3Scale(travel_distance, speed*GetFrameTime());
	// actually move the player
	last_position = position;
	position = Vector3Add(position, travel_distance);
}

void Player::update_orientation(){
	// user input
	if(IsKeyDown(KEY_RIGHT)){
		rotation -= GetFrameTime()*rotation_speed;
	}
	if(IsKeyDown(KEY_LEFT)){
		rotation += GetFrameTime()*rotation_speed;
	}
	if(IsKeyDown(KEY_DOWN)){
		head_rotation -= GetFrameTime()*rotation_speed;
	}
	if(IsKeyDown(KEY_UP)){
		head_rotation += GetFrameTime()*rotation_speed;
	}
	auto mouse_delta = GetMouseDelta();
	SetMousePosition(GetRenderWidth()/2, GetRenderHeight()/2);

	rotation -= GetFrameTime()*rotation_speed*mouse_delta.x;
	head_rotation -= GetFrameTime()*rotation_speed*mouse_delta.y;
	
	// angle security
	if(rotation > 2*PI){
		rotation -= 2*PI;
	}
	else if(rotation < 0){
		rotation += 2*PI;
	}

	// head angle limitation
	if(head_rotation > PI/4){
		head_rotation = PI/4;
	}
	else if(head_rotation < -PI/4){
		head_rotation = -PI/4;
	}
}

void Player::update_camera(){
	// move with player
	camera.position = Vector3Add(position, camera_postion_offset);
	// horizontal rotation
	auto tmp_target = Vector3RotateByAxisAngle(camera_target_offset, camera.up, rotation);
	// vertical rotation
	tmp_target = Vector3RotateByAxisAngle(tmp_target, Vector3Perpendicular(tmp_target), head_rotation);
	/// to player space
	camera.target = Vector3Add(camera.position, tmp_target);
}

void Player::check_collisions(){
	// calculate grid position
	Vector2 grid_pos = {
		round(position.x / maze->maze_scale) + floor(maze->map.size()/2.0f),
		round(position.z / maze->maze_scale) + floor(maze->map[0].size()/2.0f)
	};
    std::string x_pos_s = std::to_string(grid_pos.x);
    std::string y_pos_s = std::to_string(grid_pos.y);
    pos_text->updateText(x_pos_s+";"+y_pos_s+";"+ std::to_string(maze->map.size()));
    // win check
    if(grid_pos.x < 0 || grid_pos.y < 0){
        ScreenManager& manager = ScreenManager::getInstance();
        manager.go_to_screen("Win");
        return;
    }
	// check occupancy
	if(!maze->map[grid_pos.x][grid_pos.y]){
		return;
	}
	// correct position
	position = last_position;
}

// Devirtualising
void Player::Draw2D(){}
void Player::Draw3D(){}

Player::Player(){
	// basic init
    initialize();
    speed = 5.0f;
	rotation_speed = 1.0f;
	// camera init
	camera_postion_offset = {0.0f,1.0f,0.0f};
	camera = {
		.position = Vector3Add(position, camera_postion_offset),
		.target = Vector3Add(Vector3Add(position, camera_postion_offset), camera_target_offset),
		.up = {0.0f, 1.0f, 0.0f},
		.fovy = 60.0f,
		.projection = CAMERA_PERSPECTIVE,
	};
	UpdateCamera(&camera, CAMERA_CUSTOM);
}

void Player::Update(){
    if(paused){
        return;
    }
	update_orientation();
	update_position();
	check_collisions();
	update_camera();
}

void Player::initialize() {
    position = {0.0f, 0.0f,0.0f};
    rotation = PI/2;
    head_rotation = 0.0f;
    camera_target_offset = {0.0f, 0.0f, 1.0f};
}
