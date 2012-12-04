/*
 * DataImportUI.cpp
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#include "DataImportUI.h"
#include <Wt/WPushButton>
#include <Wt/WText>
using namespace Wt;
namespace DataCenter
{

DataImportUI::DataImportUI(Session *session, Wt::WContainerWidget *parent)
{
	setContentAlignment(AlignCenter);

}

DataImportUI::~DataImportUI()
{
}

void DataImportUI::update(void)
{
	new WText("<h2>Hall of fame</h2>", this);
	WPushButton *b = new WPushButton("DataImport", this);
	b->show();
}

} /* namespace DataCenter */
