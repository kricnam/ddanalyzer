/*
 * HomeUI.cpp
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#include "HomeUI.h"
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WGridLayout>
#include <Wt/WLabel>
#include <Wt/WString>

using namespace Wt;
namespace DataCenter
{

HomeUI::HomeUI(WContainerWidget *parent)
{
	  setContentAlignment(AlignCenter);
	  new WLabel(WString::fromUTF8("用户名",false),this);
	  new WLineEdit(this);
	  new WBreak(this);
	  WPushButton *button
	        = new WPushButton(WString::fromUTF8("登录",false),this);



}

HomeUI::~HomeUI()
{
	// TODO Auto-generated destructor stub
}

} /* namespace DataCenter */
