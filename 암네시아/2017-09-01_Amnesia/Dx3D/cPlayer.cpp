#include "stdafx.h"
#include "cPlayer.h"
#include "cSkinnedMesh.h"
#include "cPlayer_Ctrl.h"
#include "cAllocateHierarchy.h"
#include "cObject_Light.h"
#include "cScene_Shader_Scene_Test.h"
#include "cRay.h"
#include "cObject_Item.h"
#include "cScene.h"
#include "cCursorStatus.h"
#include "cUI_In_Game.h"



cPlayer::cPlayer()
{
	m_pPlayerCtrl = NULL;
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_PTarget_Mesh = m_pPlayer_animation_Vec[0];


	

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f,0.f,0.f), 1.0f);
	m_pPlayer_Animation_Index = cPlayer_Animation_HAND;
}

cPlayer::cPlayer(vector<cObject_Light*>* Light_Object)
{
	m_pPlayerCtrl = NULL;
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_PTarget_Mesh = m_pPlayer_animation_Vec[0];

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f, 0.f, 0.f), 0.5f);

	m_pPlayer_Animation_Index = cPlayer_Animation_HAND;
}

cPlayer::cPlayer(void * Light_Object)
{
	m_pPlayerCtrl = NULL;
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_PTarget_Mesh = m_pPlayer_animation_Vec[0];

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f, 0.f, 0.f), 1.0f);
	m_pPlayer_Animation_Index = cPlayer_Animation_HAND;

	m_Light_Vector = Light_Object;
	m_Mat_vec.resize(4);

	Return_Name((ST_BONE*)m_pPlayer_animation_Vec[0]->m_pRootFrame,"index", &m_Mat_vec[0]);
}

cPlayer::cPlayer(cScene *Save, D3DXVECTOR3 cPlayer_Pos)
{
	//메인 이게 메인이다.
	m_pPlayerCtrl = NULL;
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_PTarget_Mesh = m_pPlayer_animation_Vec[0];

	m_pPlayerCtrl = new cPlayer_Ctrl(cPlayer_Pos, 1.0f);
	m_pPlayer_Animation_Index = cPlayer_Animation_HAND;

	m_pMy_Scene = (cScene_Shader_Scene_Test*)Save;

	m_Mat_vec.resize(4);

	Return_Name((ST_BONE*)m_pPlayer_animation_Vec[0]->m_pRootFrame, "index", &m_Mat_vec[0]);
	Return_Name((ST_BONE*)m_pPlayer_animation_Vec[1]->m_pRootFrame, "index", &m_Mat_vec[1]);
	Return_Name((ST_BONE*)m_pPlayer_animation_Vec[2]->m_pRootFrame, "index", &m_Mat_vec[2]);
	Return_Name((ST_BONE*)m_pPlayer_animation_Vec[3]->m_pRootFrame, "index", &m_Mat_vec[3]);

	cObject = cMESH_MANAGER->FIND("PLAYERMESH_TAG_LANTERN");
	m_pLantern = new cSkinnedMesh("X_File/entities/lantern/", "hand_lantern.X");

	{
		m_Lantern.x = 20.0403633;
		m_Lantern.y = 32.0006371;
		m_Lantern.z = 9.43012047;
		m_Lantern.k = -0.615995646;
		m_Lantern.l = -0.927991629;
		x = 20.0403633;
		y = 32.0006371;
		z = 9.43012047;
		k = -0.615995646;
		l = -0.927991629;
	}
	
	m_Lantern.m_Normal_Effect = cMESH_MANAGER->LoadShader("Test/Lantern.fx");



}

cPlayer::~cPlayer()
{
	SAFE_DELETE(m_pPlayerCtrl);
	for each(auto p in m_pPlayer_animation_Vec)
		SAFE_DELETE(p);
}

void cPlayer::Update()
{
	SAFE_UPDATE(m_pPlayerCtrl);
	if(m_PTarget_Mesh)Animation_Change();
	cLight_Object_Picking_Update();
	cObject_Item_OutLine_Update();
}

void cPlayer::Render()
{
	if (m_PTarget_Mesh)
	{
		D3DXVECTOR3 m_Camera = m_pPlayerCtrl->Get_m_Camera();
		D3DXVECTOR3 Hand_Vector = D3DXVECTOR3(m_Camera.x, m_Camera.y, m_Camera.z);
		cLight_Seting = D3DXVECTOR3(m_Camera.x, m_Camera.y, m_Camera.z);
		D3DXMATRIX Hands_Matrix, matS, matR;
		D3DXMatrixIsIdentity(&Hands_Matrix);
		D3DXMatrixIsIdentity(&matS);
		D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
		D3DXMatrixTranslation(&Hands_Matrix, Hand_Vector.x, Hand_Vector.y, Hand_Vector.z);
		Hands_Matrix = matS * m_pPlayerCtrl->Get_m_pTarget_Matrix() * Hands_Matrix;
		if(m_pPlayer_Animation_Index != cPlayer_Animation_HAND) m_PTarget_Mesh->UpdateAndRender(Hands_Matrix);
	}	
	if (m_pPlayer_Animation_Index != cPlayer_Animation_HAND)Lantern_Rander();
	

	
}

void cPlayer::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pPlayerCtrl)
		m_pPlayerCtrl->MsgProc( hWnd, message, wParam, lParam);
}

void cPlayer::Animation_Change()
{
	bool KeyCheck = false;
	if (KEYMANAGER->isStayKeyDown('F') && DATABASE->GetOilValue() > 0)
	{
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND)
		{
			SOUNDMANAGER->play("ui_lantern_on");
			Animation_Change_Set(cPlayer_Animation_HAND_UP, &Save_ANI);
		}
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_UP)
		{
			if (GetTickCount64() >= Save_ANI)
			{
				Animation_Change_Set(cPlayer_Animation_HAND_STAY);
			}
		}
	
				
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_UP || m_pPlayer_Animation_Index == cPlayer_Animation_HAND_STAY)
		{
			DATABASE->SetOilValue(DATABASE->GetOilValue() - 0.0001f);
			
			KeyCheck = true;
			if (cLight_Color_Seting.x < 0.8f) cLight_Color_Seting.x += 0.04f;
			if (cLight_Color_Seting.y < 0.6f) cLight_Color_Seting.y += 0.04f;
			if (DATABASE->GetOilValue() <= 0)
			{
				SOUNDMANAGER->play("ui_lantern_off");
				Animation_Change_Set(cPlayer_Animation_HAND_DOWN, &Save_ANI);
			}
		}


	}
	if (KEYMANAGER->isOnceKeyUp('F') && DATABASE->GetOilValue() > 0.0f)
	{
		SOUNDMANAGER->play("ui_lantern_off");
		Animation_Change_Set(cPlayer_Animation_HAND_DOWN, &Save_ANI);
	}

	if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_DOWN)
	{
		if (GetTickCount64() >= Save_ANI)
		{
			Animation_Change_Set(cPlayer_Animation_HAND);
		}
	}
		
	
	if (!KeyCheck)
	{
		if (cLight_Color_Seting.x > 0.0f) cLight_Color_Seting.x -= 0.04f;
		if (cLight_Color_Seting.y > 0.0f) cLight_Color_Seting.y -= 0.04f;
	}
}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type)
{
	
	m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
	m_PTarget_Mesh->Anireset();
	m_pPlayer_Animation_Index = Set_Type;
}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type, float * SaveTarget)
{
	m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
	*SaveTarget = GetTickCount64() + (m_PTarget_Mesh->Get_Return_ANIM_Time() * 1000.f);
	m_PTarget_Mesh->Anireset();
	m_pPlayer_Animation_Index = Set_Type;
}

void cPlayer::set_m_Light_Vector(void * Vector)
{
	m_Light_Vector = Vector;
}

void cPlayer::cLight_Object_Picking_Update()
{

	for (int i = 0; i < m_pMy_Scene->cObject_Light_vec.size(); ++i)
	{
		POINT DD = _ptMousePos;
		ST_SPHERE Save;
		Save.p = m_pMy_Scene->cObject_Light_vec[i]->m_ParticlePosition;
		Save.r = 1.0f;
		cRay Pick;
		Pick = cRay::RayAtWorldSpace(730, 330);
		Save.isPicked = Pick.IsPicked(&Save);
		if (Save.isPicked)
		{
			
			int D = 0;
			if (m_pMy_Scene->cObject_Light_vec[i]->m_Fire_On)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
				{
					m_pMy_Scene->cObject_Light_vec[i]->SetFire(false);
				}
				
			}
			else
			{
				m_pMy_Scene->m_pCursorStatus->CursorStatus(CURSORSTATUS::CUR_IGNITE);
				if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
				{
					SOUNDMANAGER->play("ui_use_tinderbox");
					m_pMy_Scene->cObject_Light_vec[i]->SetFire(true);
				}
			}
		}
		

	}
}

void cPlayer::cObject_Item_OutLine_Update()
{
	for (int i = 0; i < m_pMy_Scene->cObject_Item_vec.size(); ++i)
	{
		if (!m_pMy_Scene->cObject_Item_vec[i]->m_Render_On)continue;
		m_pMy_Scene->cObject_Item_vec[i]->m_OutLine_On = false;
		ST_SPHERE Save;
		Save.p = m_pMy_Scene->cObject_Item_vec[i]->m_Pos;
		Save.r = 0.2f;
		cRay Pick;
		Pick = cRay::RayAtWorldSpace(730, 330);
		Save.isPicked = Pick.IsPicked(&Save);
		if (Save.isPicked)
		{
			m_pMy_Scene->cObject_Item_vec[i]->m_OutLine_On = true;
			m_pMy_Scene->m_pCursorStatus->CursorStatus(CURSORSTATUS::CUR_PICKUP);
			if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
			{
				m_pMy_Scene->cObject_Item_vec[i]->m_Render_On = false;
				SOUNDMANAGER->play("pick_potion");
				switch (m_pMy_Scene->cObject_Item_vec[i]->Item_Tag)
				{
				case ITEMMESH_TAG_POTION_OIL:
				{
					m_pMy_Scene->m_pUI_In_Game->CreateItem(ITEM_OIL);
				}
					break;
				case ITEMMESH_TAG_POTION_TINDERBOX:
				{
					DATABASE->Insert(ITEM_TINDER);
				}
				break;
				case ITEMMESH_TAG_POTION_HEALTH:
				{
					m_pMy_Scene->m_pUI_In_Game->CreateItem(ITEM_HP);
				}
				break;
				case ITEMMESH_TAG_POTION_SANITY:
				{
					m_pMy_Scene->m_pUI_In_Game->CreateItem(ITEM_MENTAL);
				}
				break;
				}
				
			}
		}
	}
}

void cPlayer::cFind_Hand(cSkinnedMesh* Insert, D3DXMATRIXA16* out)
{

	//Insert->m_pRootFrame
}

void cPlayer::Return_Name(ST_BONE * Insert, LPSTR NAME, D3DXMATRIXA16 **Out)
{
	if (Insert->Name == NULL)
	{
		if (Insert->pFrameFirstChild)
		{
			Return_Name((ST_BONE*)Insert->pFrameFirstChild, NAME, Out);
		}
		if (Insert->pFrameSibling)
		{
			Return_Name((ST_BONE*)Insert->pFrameSibling, NAME, Out);
		}
	}
	else
	{
		if (!strcmp(Insert->Name, NAME))
		{
			*Out = &Insert->CombinedTransformationMatrix;
		}
		else
		{
			if (Insert->pFrameFirstChild)
			{
				Return_Name((ST_BONE*)Insert->pFrameFirstChild, NAME, Out);
			}
			if (Insert->pFrameSibling)
			{
				Return_Name((ST_BONE*)Insert->pFrameSibling, NAME, Out);
			}
			//Return_Name(Insert->);
		}
	}
}

void cPlayer::Return_Name(ST_BONE * Insert, LPSTR NAME, ST_BONE ** Out)
{
	if (Insert->Name == NULL)
	{
		if (Insert->pFrameFirstChild)
		{
			Return_Name((ST_BONE*)Insert->pFrameFirstChild, NAME, Out);
		}
		if (Insert->pFrameSibling)
		{
			Return_Name((ST_BONE*)Insert->pFrameSibling, NAME, Out);
		}
	}
	else
	{
		if (!strcmp(Insert->Name, NAME))
		{
			*Out = Insert;
		}
		else
		{
			if (Insert->pFrameFirstChild)
			{
				Return_Name((ST_BONE*)Insert->pFrameFirstChild, NAME, Out);
			}
			if (Insert->pFrameSibling)
			{
				Return_Name((ST_BONE*)Insert->pFrameSibling, NAME, Out);
			}
			//Return_Name(Insert->);
		}
	}
}

void cPlayer::Lantern_Rander()
{
	D3DXMATRIXA16 m_Rentern, Rx, Rz, Ry, TransY, i, ii;
	D3DXMatrixIdentity(&i);
	D3DXMatrixTranslation(&ii, k, -0.01f, l);
	i *= ii;

	D3DXMatrixRotationX(&Rx, x);
	D3DXMatrixRotationY(&Ry, y);
	D3DXMatrixRotationZ(&Rz, z);
	
	switch (m_pPlayer_Animation_Index)
	{
	case cPlayer_Animation_HAND:
	{
		m_Rentern = ii *Rx * Ry *Rz * *m_Mat_vec[0];
	}
	break;
	case cPlayer_Animation_HAND_UP:
	{
		m_Rentern = ii *Rx * Ry *Rz * *m_Mat_vec[1];
	}
	break;
	case cPlayer_Animation_HAND_STAY:
	{
		m_Rentern = ii *Rx * Ry *Rz * *m_Mat_vec[2];
	}
	break;
	case cPlayer_Animation_HAND_DOWN:
	{
		m_Rentern = ii *Rx * Ry *Rz * *m_Mat_vec[3];
	}
	break;
	}
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_Rentern);
	m_Lantern.m_Normal_Effect->SetMatrix("g_Worldmat", &m_Rentern);

	D3DXMATRIXA16 matView, matProjection;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_Rentern);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR4	gWorldCameraPosition(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f);

	m_Lantern.m_Normal_Effect->SetMatrix("gWorldMatrix", &m_Rentern);
	m_Lantern.m_Normal_Effect->SetMatrix("gWorldViewProjectionMatrix", &(m_Rentern*matView * matProjection));

	
	


	m_Lantern.m_Normal_Effect->SetVector("gWorldCameraPosition", &gWorldCameraPosition);
	m_Lantern.m_Normal_Effect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Lantern.m_Normal_Effect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));
	m_Lantern.m_Normal_Effect->SetVector("gLightColor_3", &D3DXVECTOR4(cLight_Color_Seting_3.x, cLight_Color_Seting_3.y, cLight_Color_Seting_3.z, 1));
	m_Lantern.m_Normal_Effect->SetVector("NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Lantern.m_Normal_Effect->SetMatrix("gViewMatrix", &matView);
	m_Lantern.m_Normal_Effect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Lantern.m_Normal_Effect->SetTexture("DiffuseMap_Tex", cObject->m_Texture);
	m_Lantern.m_Normal_Effect->SetTexture("NormalMap_Tex", cObject->m_Normal);
	m_Lantern.m_Normal_Effect->SetTexture("SpecularMap_Tex", cObject->m_Specqural);



	UINT numPasses = 0;
	m_Lantern.m_Normal_Effect->Begin(&numPasses, NULL);

	for (UINT i = 0; i < numPasses; ++i)
	{
		m_Lantern.m_Normal_Effect->BeginPass(i);

		cObject->m_Mesh->DrawSubset(0);

		m_Lantern.m_Normal_Effect->EndPass();
	}
	m_Lantern.m_Normal_Effect->End();
}

D3DXVECTOR3 cPlayer::Get_cPlayer_Pos()
{
	return *m_pPlayerCtrl->Get_m_Pos();
}

D3DXVECTOR3 * cPlayer::Get_p_cPlayer_Pos()
{
	return m_pPlayerCtrl->Get_m_Pos();
}

void cPlayer::cPlayer_Start_Seting()
{
}

void cPlayer::Surface_Insert(D3DXVECTOR3 Save)
{
	m_pPlayerCtrl->m_surface_Insert(Save);
}


