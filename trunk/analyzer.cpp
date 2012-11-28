//============================================================================
// Name        : analyzer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WGridLayout>
// c++0x only, for std::bind
// #include <functional>

using namespace Wt;

/*
 * A simple hello world application class which demonstrates how to react
 * to events, read input, and give feed-back.
 */
class DataAnalyzer : public WApplication
{
public:
  DataAnalyzer(const WEnvironment& env);

private:
  WLineEdit *nameEdit_;
  WText *greeting_;
  WPushButton *p;
  void greet();
};

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
DataAnalyzer::DataAnalyzer(const WEnvironment& env)
  : WApplication(env)
{
  setTitle(WString::fromUTF8("行车数据管理平台",true));
  WContainerWidget *w = new WContainerWidget(root());
  //w->resize(WLength::Auto, WLength::Auto);

  root()->setContentAlignment(AlignCenter);
  WGridLayout *layout = new WGridLayout();
  WPushButton *button
      = new WPushButton("Greet me.", root());
  button->setAttributeValue("style","height:150px;width:150px;");
  p = new WPushButton("Greet me2.", root());
  p->setAttributeValue("style","height:150px;width:150px;");
  layout->addWidget(button, 0, 0, Wt::AlignCenter);
  layout->addWidget(p, 0, 1, Wt::AlignCenter);
  layout->addWidget(new Wt::WText("Item 1 0"), 1, 0);
  layout->addWidget(new Wt::WText("Item 1 1"), 1, 1);
  w->setLayout(layout);
  p->setAttributeValue("style","height:150px;width:150px;");
  button->setAttributeValue("style","height:150px;width:150px;");
  root()->addWidget(w);
  nameEdit_ = new WLineEdit(root());                     // allow text input
  nameEdit_->setFocus();                                 // give focus

              // create a button
  button->setMargin(15, Left);                            // add 5 pixels margin
  root()->addWidget(new WBreak());                       // insert a line break

  greeting_ = new WText(root());                         // empty text

  /*
   * Connect signals with slots
   *
   * - simple Wt-way
   */
  button->clicked().connect(this, &DataAnalyzer::greet);

  /*
   * - using an arbitrary function object (binding values with boost::bind())
   */
  nameEdit_->enterPressed().connect
    (boost::bind(&DataAnalyzer::greet, this));

  /*
   * - using a c++0x lambda:
   */
  // b->clicked().connect(std::bind([=]() {
  //       greeting_->setText("Hello there, " + nameEdit_->text());
  // }));
}

void DataAnalyzer::greet()
{
  /*
   * Update the text, using text input into the nameEdit_ field.
   */
  greeting_->setText("Hello there, " + nameEdit_->text());
  p->setAttributeValue("style","height:100px;width:100px;");
}

WApplication *createApplication(const WEnvironment& env)
{

  return new DataAnalyzer(env);
}

int main(int argc, char **argv)
{
  return WRun(argc, argv, &createApplication);
}

