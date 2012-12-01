/*
 * HomeUI.h
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#ifndef HOMEUI_H_
#define HOMEUI_H_

#include <Wt/WContainerWidget>
#include "Session.h"
using namespace Wt;

namespace DataCenter
{

class HomeUI: public WContainerWidget
{
public:
	HomeUI(WContainerWidget *parent);
	virtual ~HomeUI();

	WContainerWidget *links_;
//	WAnchor *backToGameAnchor_;
//	WAnchor *scoresAnchor_;

	Session session_;

	void onAuthEvent();
	void showGame();
	void showHighScores();
};

} /* namespace DataCenter */
#endif /* HOMEUI_H_ */
