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
	pFileName = new WText(this);
	pDriverInfo = new WText(this);
}

USBFileContentView::~USBFileContentView()
{

}

} /* namespace DataCenter */
