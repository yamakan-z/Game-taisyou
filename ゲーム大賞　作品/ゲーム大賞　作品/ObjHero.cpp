//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	 m_px=100.0f;//位置
	 m_py=0.0f;
	 m_vx=0.0f;//移動ベクトル
	 m_vy=0.0f;
	 m_posture = 1.0f;//右向き0.0f左向き1.0f

	 //blockとの衝突状態確認
	 m_hit_up = false;
	 m_hit_down = false;
	 m_hit_left = false;
	 m_hit_right = false;
}

//アクション
void CObjHero::Action()
{
	//落下によるゲームオーバー
	if (m_py > 1000.0f)
	{
		//場外に出たらリスタート
		Scene::SetScene(new CSceneGameOver());
	}

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = +5.0f;
		m_posture = 1.0f;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = -5.0f;
		m_posture = 0.0f;
	}

	//摩擦
	m_vx += -(m_vx * 0.098);

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 656.0f;
	src.m_bottom = 800.0f;

	//表示位置の設定
	dst.m_top = 0.0f+m_py;
	dst.m_left =( 64.0f*m_posture)+m_px;
	dst.m_right = (64.0-64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}