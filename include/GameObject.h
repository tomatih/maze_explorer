#ifndef _GAMEOBJECTH_
#define _GAMEOBJECTH_

class GameObject{
public:
	virtual void Draw2D() = 0;
	virtual void Draw3D() = 0;
	virtual void Update() = 0;
};

#endif