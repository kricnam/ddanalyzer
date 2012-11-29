/*
 * HomeUI.h
 *
 *  Created on: Nov 28, 2012
 *      Author: mxx
 */

#ifndef HOMEUI_H_
#define HOMEUI_H_

#include <Wt/WContainerWidget>
using namespace Wt;

namespace DataCenter
{

class HomeUI: public WContainerWidget
{
public:
	HomeUI(WContainerWidget *parent);
	virtual ~HomeUI();
};

} /* namespace DataCenter */
#endif /* HOMEUI_H_ */
