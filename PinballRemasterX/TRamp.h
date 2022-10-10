#pragma once

#include "TCollisionComponent.h"
#include "TEdgeManager.h"

struct ramp_plane_type;

class TRamp :
	public TCollisionComponent
{
public:
	TRamp(TPinballTable* table, int groupIndex);
	void Collision(TBall* ball, vector2* nextPosition, vector2* direction, float distance,
	               TEdgeSegment* edge) override;
	int FieldEffect(TBall* ball, vector2* vecDst) override;
	void port_draw() override;

	field_effect_type Field{};
	int CollisionGroup;
	bool BallZOffsetFlag;
	int RampPlaneCount;
	float BallFieldMult;
	ramp_plane_type* RampPlane;
	TEdgeSegment* Line2;
	TEdgeSegment* Line3;
	TEdgeSegment* Line1;
	int Wall1CollisionGroup;
	int Wall2CollisionGroup;
	float Wall1BallOffset;
	float Wall2BallOffset;
};
