/*
 * USBFileConetenView.h
 *
 *  Created on: Jan 6, 2013
 *      Author: mxx
 */

#ifndef USBFILECONETENVIEW_H_
#define USBFILECONETENVIEW_H_

#include <Wt/WContainerWidget>
#include <Wt/WText>
using namespace Wt;
namespace DataCenter
{

class USBFileContentView: public Wt::WContainerWidget
{
public:
	USBFileContentView(WContainerWidget *parent = 0);
	virtual ~USBFileContentView();

	WText* pFileName;
	WText* pDriverInfo;
};

} /* namespace DataCenter */
#endif /* USBFILECONETENVIEW_H_ */
