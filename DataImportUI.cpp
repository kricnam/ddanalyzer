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

using namespace Wt;
namespace DataCenter
{

DataImportUI::DataImportUI(Session *session, Wt::WContainerWidget *parent) :
		WContainerWidget(parent)
{
	setContentAlignment(AlignCenter);
	new WText(WString::fromUTF8("<h2>功能选择</h2>"), this);
}

DataImportUI::~DataImportUI()
{
}

void DataImportUI::update(void)
{
	WPushButton *b = new WPushButton(WString::fromUTF8("数据导入"), this);

	b->setWidth(100);
	b->setHeight(100);
	b->clicked().connect(this, &DataImportUI::uploadPrompt);
	b->show();
}

void DataImportUI::uploadPrompt(void)
{
	log("info") << "upload";

	Wt::WFileUpload *upload = new Wt::WFileUpload(this);
	upload->setFileTextSize(40);

	// Provide a button
	Wt::WPushButton *uploadButton = new Wt::WPushButton("Send", this);

	// Upload when the button is clicked.
	uploadButton->clicked().connect(upload, &Wt::WFileUpload::upload);
	uploadButton->clicked().connect(uploadButton, &Wt::WPushButton::disable);

	// Upload automatically when the user entered a file.
	upload->changed().connect(upload, &WFileUpload::upload);
	upload->changed().connect(uploadButton, &Wt::WPushButton::disable);

	// React to a succesfull upload.
	upload->uploaded().connect(this, &DataImportUI::fileUploaded);

	// React to a fileupload problem.
	upload->fileTooLarge().connect(this, &DataImportUI::fileTooLarge);

	upload->show();
}

void DataImportUI::fileUploaded(void)
{

}

void DataImportUI::fileTooLarge(void)
{

}

} /* namespace DataCenter */
