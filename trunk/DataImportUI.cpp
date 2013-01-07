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
#include <Wt/WAnimation>

using namespace Wt;
namespace DataCenter
{

DataImportUI::DataImportUI(Session *session, Wt::WContainerWidget *parent) :
		WContainerWidget(parent)
{
	log("info") << "DataImportUI";
	setContentAlignment(AlignCenter);
	result = NULL;
	button = NULL;
	ptrUpload = NULL;
	pView = NULL;
}

DataImportUI::~DataImportUI()
{
	log("info") << "DataImportUI delete";
}

void DataImportUI::update(void)
{
	log("info") << "DataImportUI update";
	new WText(WString::fromUTF8("<h2>功能选择</h2>"), this);
	button = new WPushButton(WString::fromUTF8("数据导入"), this);

	button->setWidth(100);
	button->setHeight(100);
	button->clicked().connect(this, &DataImportUI::uploadPrompt);
	button->show();
}

void DataImportUI::uploadPrompt(void)
{
	if (result)
		return;

	button->setStyleClass("side-bar");
	result = new WContainerWidget(this);
	ptrUpload = new WFileUpload(result);
	ptrUpload->setProgressBar(new WProgressBar());
	ptrUpload->changed().connect(ptrUpload, &WFileUpload::upload);
	ptrUpload->uploaded().connect(this, &DataImportUI::fileUploaded);
	ptrUpload->fileTooLarge().connect(this, &DataImportUI::fileTooLarge);
}

void DataImportUI::fileUploaded(void)
{

	if (result)
	{
		string strTmp = ptrUpload->spoolFileName();
		new WText(strTmp, this);

		new WText(ptrUpload->clientFileName(), this);
		delete result;
		result = NULL;
		pView = new USBFileContentView(this);

	}

}

void DataImportUI::fileTooLarge(void)
{
	if (result)
	{
		WString strTmp = ptrUpload->clientFileName();
		log("info") << strTmp;
		strTmp += " too  large";
		new WText(strTmp, this);
		delete result;
		result = NULL;

	}

}

} /* namespace DataCenter */
