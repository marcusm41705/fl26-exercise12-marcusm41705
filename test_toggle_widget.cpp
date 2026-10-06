#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:
 
  // Define tests here
  void toggle_testing();
};

// Implement the tests here
void TestToggleWidget::toggle_testing(){
  ToggleWidget w1;
  QPushButton *button = w1.findChild<QPushButton *>();
  QRadioButton *light = w1.findChild<QRadioButton *>();
  //check initial states
  QVERIFY(button != nullptr);
  QVERIFY(light != nullptr);
  QVERIFY(!light->isChecked());
  //code to test that when the button is clicked the radio button
  //toggles on and off
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(light->isChecked()); //light on
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(!light->isChecked()); //light off
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
