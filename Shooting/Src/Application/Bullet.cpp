#include"Bullet.h"

void C_Bullet::Init()
{
	for (int b = 0; b < bulletNum; b++)
	{
		mybullet[b].m_pos = { 0,0 };
		mybullet[b].m_scale = { 1,1 };
		mybullet[b].m_move = { 0,0 };


		startBulletFlg[b] = false;
		chargeBulletFlg[b] = false;
	}
	bu = 0;
	shotTime = 0;

	myBulletTex.Load("Texture/自機　弾/Blue Effect Bullet Impact Explosion 32x32.png");
}

void C_Bullet::UpDate()
{
	
		for (int b = 0; b < bulletNum; b++)
		{
			mybullet[b].m_pos += mybullet[b].m_move;

			if (mybullet[b].m_pos.x >= Width)
			{
				mybullet[b].m_pos.x = 0;
				mybullet[b].m_move.x = 0;
				mybullet[b].m_scale = { 1,1 };
				chargeBulletFlg[b] = false;
				startBulletFlg[b] = false;
				bu = b;

			}
			//if (bu < bulletNum)
			{
				if (shotTime <= 0)	//弾の発射クールタイムがゼロになったら
				{
					if (GetAsyncKeyState('A') & 0x8000)
					{
						if (startBulletFlg[b] == false)	//もしその弾が発射されていなければ
						{
							chargeBulletFlg[b] = true;
							mybullet[b].m_scale.x += 0.01;	//チャージで大きく
							mybullet[b].m_scale.y += 0.01;
						}
					}
					else
					{
						if (chargeBulletFlg[b] == true)	//チャージが完了していれば
						{
							startBulletFlg[b] = true;		//発射フラグ
							chargeBulletFlg[b] = false;
							mybullet[b].m_move.x = 3;		//発射
							shotTime++;						//クールタイム
						}
						else
						{
							startBulletFlg[b] = true;		//発射フラグ
							mybullet[b].m_move.x = 3;		//発射
							shotTime++;						//クールタイム
						}
					}
				}
				else
				{
					if (shotTime >= 10)
					{
						shotTime = 0;
						//Flg	//次の弾が発射
					}
					else
					{
						if (chargeBulletFlg[b] == false)
						{
							shotTime++;
						}
					}
				}
			}
		}

		
		//if (bu < bulletNum)
		//{
		//	if (shotTime <= 0)	//弾の発射クールタイムがゼロになったら
		//	{
		//		if (GetAsyncKeyState('A') & 0x8000)
		//		{
		//			if (startBulletFlg[bu] == false)	//もしその弾が発射されていなければ
		//			{
		//				chargeBulletFlg[bu] = true;
		//				mybullet[bu].m_scale.x += 0.01;	//チャージで大きく
		//				mybullet[bu].m_scale.y += 0.01;
		//			}
		//		}
		//		else
		//		{
		//			if (chargeBulletFlg[bu] == true)	//チャージが完了していれば
		//			{
		//				startBulletFlg[bu] = true;		//発射フラグ
		//				chargeBulletFlg[bu] = false;
		//				mybullet[bu].m_move.x = 3;		//発射
		//				shotTime++;						//クールタイム
		//			}
		//			else
		//			{
		//				startBulletFlg[bu] = true;		//発射フラグ
		//				mybullet[bu].m_move.x = 3;		//発射
		//				shotTime++;						//クールタイム
		//			}
		//		}
		//	}
		//	else
		//	{
		//		if (shotTime >= 10)
		//		{
		//			shotTime = 0;
		//			bu++;	//次の弾が発射
		//		}
		//		else
		//		{
		//			if (chargeBulletFlg[bu] == false)
		//			{
		//				shotTime++;
		//			}
		//		}
		//	}
		//}
		
		

		for (int b = 0; b < bulletNum; b++)
		{
			mybullet[b].m_scaleMat = Math::Matrix::CreateScale(mybullet[b].m_scale.x, mybullet[b].m_scale.y, 0);
			mybullet[b].m_transMat = Math::Matrix::CreateTranslation(mybullet[b].m_pos.x, mybullet[b].m_pos.y, 0);

			mybullet[b].m_Mat = mybullet[b].m_scaleMat * mybullet[b].m_transMat;
		}
}

void C_Bullet::Alive()
{

}

void C_Bullet::Draw()
{
	for (int b = 0; b < bulletNum; b++)
	{
		SHADER.m_spriteShader.SetMatrix(mybullet[b].m_Mat);
		SHADER.m_spriteShader.DrawTex(&myBulletTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
	}
}

void C_Bullet::Release()
{
	myBulletTex.Release();
}
