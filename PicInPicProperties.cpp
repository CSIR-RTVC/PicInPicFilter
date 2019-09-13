#include "PicInPicProperties.h"

CUnknown * WINAPI PicInPicProperties::CreateInstance(LPUNKNOWN pUnk, HRESULT *pHr)
{
  PicInPicProperties *pNewObject = new PicInPicProperties(pUnk);
  if (pNewObject == NULL)
  {
    *pHr = E_OUTOFMEMORY;
  }
  return pNewObject;
}

PicInPicProperties::PicInPicProperties(IUnknown *pUnk) :
FilterPropertiesBase(NAME("Pic in pic Properties"), pUnk, IDD_PIC_IN_PIC_DIALOG, IDS_PIC_IN_PIC_CAPTION)
{

}

HRESULT PicInPicProperties::ReadSettings()
{
  initialiseControls();

  HRESULT hr = setEditTextFromIntFilterParameter(FILTER_PARAM_TARGET_HEIGHT, IDC_EDIT_TARGET_HEIGHT);
  if (FAILED(hr)) return hr; 
  
  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_TARGET_WIDTH, IDC_EDIT_TARGET_WIDTH);
  if (FAILED(hr)) return hr;

  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_SUB_PIC_WIDTH, IDC_EDIT_SUBPICTURE_WIDTH);
  if (FAILED(hr)) return hr;

  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_SUB_PIC_HEIGHT, IDC_EDIT_SUBPICTURE_HEIGHT);
  if (FAILED(hr)) return hr;

  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_OFFSET_X, IDC_EDIT_SUBPICTURE_OFFSET_X);
  if (FAILED(hr)) return hr;

  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_OFFSET_Y, IDC_EDIT_SUBPICTURE_OFFSET_Y);
  if (FAILED(hr)) return hr;

  hr = setEditTextFromIntFilterParameter(FILTER_PARAM_BORDER_WIDTH, IDC_EDIT_BORDER_WIDTH);
  return hr;
}

HRESULT PicInPicProperties::OnApplyChanges(void)
{
  HRESULT hr = setIntFilterParameterFromEditText(FILTER_PARAM_TARGET_WIDTH, IDC_EDIT_TARGET_WIDTH);
  if (FAILED(hr)) return hr;

  hr = setIntFilterParameterFromEditText(FILTER_PARAM_TARGET_HEIGHT, IDC_EDIT_TARGET_HEIGHT);
  if (FAILED(hr)) return hr;

  // Subpicture dimensions
  hr = setIntFilterParameterFromEditText(FILTER_PARAM_SUB_PIC_WIDTH, IDC_EDIT_SUBPICTURE_WIDTH);
  if (FAILED(hr)) return hr;

  hr = setIntFilterParameterFromEditText(FILTER_PARAM_SUB_PIC_HEIGHT, IDC_EDIT_SUBPICTURE_HEIGHT);
  if (FAILED(hr)) return hr;

  // Use custom offset
  hr = setIntFilterParameterFromEditText(FILTER_PARAM_OFFSET_X, IDC_EDIT_SUBPICTURE_OFFSET_X);
  if (FAILED(hr)) return hr;

  hr = setIntFilterParameterFromEditText(FILTER_PARAM_OFFSET_Y, IDC_EDIT_SUBPICTURE_OFFSET_Y);
  if (FAILED(hr)) return hr;

  hr = setIntFilterParameterFromEditText(FILTER_PARAM_BORDER_WIDTH, IDC_EDIT_BORDER_WIDTH);

  return hr;
}

void PicInPicProperties::initialiseControls()
{
  InitCommonControls();

  short lower = 0;
  short upper = (short)USHRT_MAX;
  setSpinBoxRange(IDC_SPIN1, lower, upper);
  setSpinBoxRange(IDC_SPIN2, lower, upper);
  setSpinBoxRange(IDC_SPIN3, lower, upper);
  setSpinBoxRange(IDC_SPIN4, lower, upper);
  setSpinBoxRange(IDC_SPIN5, lower, upper);
  setSpinBoxRange(IDC_SPIN6, lower, upper);
  setSpinBoxRange(IDC_SPIN7, lower, upper);
}
