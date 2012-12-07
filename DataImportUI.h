/*
 * DataImportUI.h
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#ifndef DATAIMPORTUI_H_
#define DATAIMPORTUI_H_

#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include "Session.h"
using namespace Wt;

namespace DataCenter
{

class DataImportUI: public WContainerWidget
{
public:
	DataImportUI(Session *session, Wt::WContainerWidget *parent = 0);
	virtual ~DataImportUI();
	void update(void);
	void uploadPrompt(void);
	void fileUploaded(void);
	void fileTooLarge(void);
};

} /* namespace DataCenter */
#endif /* DATAIMPORTUI_H_ */
