#pragma once


// PictureCtrl

class PictureCtrl : public CStatic
{
	DECLARE_DYNAMIC(PictureCtrl)

public:
	PictureCtrl();
	virtual ~PictureCtrl();

public:
	void SetImageFile(LPCSTR szImagePath);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

private:
	IPicture *m_pPicture;
};


