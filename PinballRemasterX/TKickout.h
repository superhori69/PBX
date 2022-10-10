#pragma once
#include "maths.h"
#include "TCollisionComponent.h"
#include "TEdgeManager.h"

class TKickout :
	public TCollisionComponent
{
public:
	TKickout(TPinballTable* table, int groupIndex, bool someFlag);
	int Message(MessageCode code, float value) override;
	void Collision(TBall* ball, vector2* nextPosition, vector2* direction, float distance,
	               TEdgeSegment* edge) override;
	int FieldEffect(TBall* ball, vector2* vecDst) override;

	static void TimerExpired(int timerId, void* caller);
	static void ResetTimerExpired(int timerId, void* caller);

	int BallCaputeredFlag;
	int NotSomeFlag;
	int Timer;
	float TimerTime1;
	float TimerTime2;
	float CollisionBallSetZ;
	TBall* Ball{};
	float FieldMult;
	circle_type Circle{};
	float OriginalBallZ{};
	vector3 BallThrowDirection{};
	float ThrowAngleMult;
	float ThrowSpeedMult1;
	float ThrowSpeedMult2;
	field_effect_type Field{};
};
