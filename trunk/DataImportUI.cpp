/*
 * DataImportUI.cpp
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#include "DataImportUI.h"
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WFileUpload>
#include <Wt/WProgressBar>
#include <Wt/WLineEdit>

using namespace Wt;
namespace DataCenter
{

DataImportUI::DataImportUI(Session *session, Wt::WContainerWidget *parent) :
		WContainerWidget(parent)
{
	log("info") << "DataImportUI";
	setContentAlignment(AlignCenter);
}

DataImportUI::~DataImportUI()
{
	log("info") << "DataImportUI delete";
}

void DataImportUI::update(void)
{
	new WText(WString::fromUTF8("<h2>功能选择</h2>"), this);
	WPushButton *b = new WPushButton(WString::fromUTF8("数据导入"), this);

	b->setWidth(100);
	b->setHeight(100);
	b->clicked().connect(this, &DataImportUI::uploadPrompt);
	b->show();
}

void DataImportUI::uploadPrompt(void)
{
	log("info") << "upload";
	WContainerWidget *result = new WContainerWidget(this);
	WFileUpload * const fu = new WFileUpload(result);
	fu->setProgressBar(new WProgressBar());
	fu->changed().connect(fu, &WFileUpload::upload);
	fu->uploaded().connect(this, &DataImportUI::fileUploaded);
	fu->fileTooLarge().connect(this,&DataImportUI::fileTooLarge);

}

void DataImportUI::fileUploaded(void)
{
	log("info") << "uploaded" ;

}

void DataImportUI::fileTooLarge(void)
{

}

} /* namespace DataCenter */
