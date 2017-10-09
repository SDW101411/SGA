#pragma once

struct ST_BONE;

class cSkinnedMesh
{
	friend class cSkinnedMeshManager;
public:
	ST_BONE*					m_pRootFrame;			
private:
	//하나만 생성
	DWORD						m_dwWorkingPaletteSize;
	D3DXMATRIX*					m_pmWorkingPalette;
	LPD3DXEFFECT				m_pEffect;
	LPD3DXEFFECT				m_pEffect_2;

	// 객체마다 생성
	LPD3DXANIMATIONCONTROLLER	m_pAnimController;
	
	SYNTHESIZE(D3DXVECTOR3, m_vPosition, Position);
	SYNTHESIZE(ST_SPHERE, m_stSphere, BoundingSphere);

public:
	cSkinnedMesh(char* szFolder, char* szFilename);
	~cSkinnedMesh(void);
	
	void UpdateAndRender();
	void UpdateAndRender(D3DXMATRIX Intersept);
	void SetAnimationIndex(int nIndex);

	void SetRandomTrackPosition(); // 테스트용

	float Get_Return_ANIM_Time();
	void Anireset();
	void AniTrackReset(int index = 0);

private:
	cSkinnedMesh();
	void Load(char* szFolder, char* szFilename);
	LPD3DXEFFECT LoadEffect(char* szFilename);
	void Update(ST_BONE* pCurrent, D3DXMATRIXA16* pmatParent);
	void Render(ST_BONE* pBone = NULL);
	void SetupBoneMatrixPtrs(ST_BONE* pBone);
	void Destroy();
};

