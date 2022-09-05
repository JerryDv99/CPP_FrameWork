#pragma once

// ** enum : 열거형, [ 상수 & 정수 ], namespace로 접근


enum class SCENEID { LOGO, MENU, STAGE, EXIT };	// 심볼릭 상수


enum ENEMYID
{
	EnemyID_Goolops,
	EnemyID_Mutant,
	EnemyID_Doomboo,
	EnemyID_MAX,
};

enum BULLETID
{
	BulletID_Fire,
	BulletID_Ice,
	BulletID_MAX,
};