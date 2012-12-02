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
#include <Wt/WAnchor>

#include <Wt/WStackedWidget>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WApplication>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/AuthModel>

using namespace Wt;
namespace DataCenter
{

HomeUI::HomeUI(WContainerWidget *parent) :
		WContainerWidget(parent)
{
	setContentAlignment(AlignCenter);


	session_.login().changed().connect(this, &HomeUI::onAuthEvent);

	Auth::AuthModel *authModel = new Auth::AuthModel(Session::auth(),
			session_.users(), this);
	authModel->addPasswordAuth(&Session::passwordAuth());
	authModel->addOAuth(Session::oAuth());

	Auth::AuthWidget *authWidget = new Auth::AuthWidget(session_.login());
	authWidget->setModel(authModel);
	authWidget->setRegistrationEnabled(false);

	WText *title = new WText(WString::fromUTF8("<h1>数据管理平台</h1>"));
	addWidget(title);

	addWidget(authWidget);

	links_ = new WContainerWidget();
	links_->setStyleClass("links");
	links_->hide();
	addWidget(links_);
}

HomeUI::~HomeUI()
{
	// TODO Auto-generated destructor stub
}

void HomeUI::onAuthEvent()
{
	if (session_.login().loggedIn())
	{
		links_->show();
		//handleInternalPath(WApplication::instance()->internalPath());
	}
	else
	{

		links_->hide();
	}
}

void HomeUI::showGame()
{
}

void HomeUI::showHighScores()
{
}

} /* namespace DataCenter */
