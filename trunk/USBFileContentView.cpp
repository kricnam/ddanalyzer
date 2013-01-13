/*
 * USBFileConetenView.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: mxx
 */

#include "USBFileContentView.h"

namespace DataCenter
{

USBFileContentView::USBFileContentView(WContainerWidget *parent )
{
	new WText("FileContent",this);
	pFileName = new WText(this);
	pDriverInfo = new WText(this);
}

USBFileContentView::~USBFileContentView()
{

}

void USBFileContentView::InitView(const char* szTmpFile, const char* szFileName)
{
}

} /* namespace DataCenter */
