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

		}

	}
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			//if(shotTime==0)	
	//他の弾が先に発射されてshotTimeが0でないときにチャージから発射に切り替えても反応しない
			{
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					//if(shotTime==0)
					{
						for (int b = 0; b < bulletNum; b++)
						{
							if (startBulletFlg[b] == false)	//もしその弾が発射されていなければ
							{
								chargeBulletFlg[b] = true;
								break;
							}
						}
					}
				}
				else
				{
					for (int b = 0; b < bulletNum; b++)
					{
					if(shotTime==0 || chargeBulletFlg[b] == true)
					{
							if (startBulletFlg[b] == false)
							{
								startBulletFlg[b] = true;		//発射フラグ
								chargeBulletFlg[b] = false;
								shotTime = 10;
								break;
							}
						}
					}
				}
			}
		}

		for (int b = 0; b < bulletNum; b++)
		{
			if (startBulletFlg[b] == true)
			{
				mybullet[b].m_move.x = 3;		//発射
			}
			else if (chargeBulletFlg[b] == true)
			{
				mybullet[b].m_scale.x += 0.05;	//チャージで大きく
				mybullet[b].m_scale.y += 0.05;
			}
		}

		if (shotTime<=0)
		{
			shotTime = 0;
		}
		else
		{
			shotTime--;
		}
		

		
		

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
