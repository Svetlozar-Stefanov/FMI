#include "pch.h"

#include "Labels/Label.h"
#include "Labels/SimpleLabel.h"
#include "Labels/RichLabel.h"
#include "Labels/StandardInputLabel.h"
#include "Labels/HelpLabel.h"

#include "Labels/LabelTransformations/TextTransformation.h"
#include "Labels/LabelTransformations/CapitalizeTransformation.h"
#include "Labels/LabelTransformations/LeftTrimTransformation.h"
#include "Labels/LabelTransformations/RightTrimTransformation.h"
#include "Labels/LabelTransformations/NormalizeSpaceTransformation.h"
#include "Labels/LabelTransformations/DecorateTransformation.h"
#include "Labels/LabelTransformations/CensorTransformation.h"
#include "Labels/LabelTransformations/ReplaceTransformation.h"
#include "Labels/LabelTransformations/CompositeTransformation.h"
#include "Labels/LabelTransformations/CensorTransformationFactory.h"

#include "Labels/LabelDecorators/Decorator.h"
#include "Labels/LabelDecorators/RandomDecorator.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::mt19937;
using std::uniform_int_distribution;
using std::invalid_argument;
using std::string;

TEST(LabelTests, SimpleLabelGetText)
{
	Label& label = SimpleLabel("testText");
	ASSERT_EQ("testText", label.getText());
}

TEST(LabelTests, RichLabelGetText)
{
	Label& label = RichLable("testText", { 1.0, 1.0, 1.0 }, 12, "Calibri");
	ASSERT_EQ("testText", label.getText());
}

//StandardInputTest

//TEST(LabelTests, StandardInputLabel)
//{
//	Label* label = new StandardInputLabel(0);
//	label = new Decorator(label, new DecorateTransformation());
//
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << i << " " << label->getText() << '\n';
//	}
//	delete label;
//
//	label = new StandardInputLabel(3);
//	label = new Decorator(label, new DecorateTransformation());
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << i << " " << label->getText() << '\n';
//	}
//	delete label;
//}

TEST(LabelTests, HelpLabelTest)
{
	Label* label = new HelpLabel(new SimpleLabel("Main Text"), "Help Text");
	ASSERT_EQ("Main Text", label->getText());
	ASSERT_EQ("Help Text", dynamic_cast<HelpLabel*>(label)->getHelperText());

	label = new Decorator(label, new DecorateTransformation());
	ASSERT_EQ("-={ Main Text }=-", label->getText());
}

TEST(LabelTransformationTests, SuccessfulCapitalizeTransformation)
{
	TextTransformation& capitalize = CapitalizeTransformation();

	Label& label1 = SimpleLabel("testText");
	ASSERT_EQ("TestText", capitalize.transform(label1.getText()));

	Label& label2 = SimpleLabel("  testText");
	ASSERT_EQ("  testText", capitalize.transform(label2.getText()));

	Label& label3 = SimpleLabel("1testText");
	ASSERT_EQ("1testText", capitalize.transform(label3.getText()));

	Label& label4 = SimpleLabel("");
	ASSERT_EQ("", capitalize.transform(label4.getText()));
}

TEST(LabelTransformationTests, SuccessfulLeftTrimTransformation)
{
	TextTransformation& leftTrim = LeftTrimTransformation();

	Label& label1 = SimpleLabel("   testText");
	ASSERT_EQ("testText", leftTrim.transform(label1.getText()));

	Label& label2 = SimpleLabel("testText  ");
	ASSERT_EQ("testText  ", leftTrim.transform(label2.getText()));

	Label& label3 = SimpleLabel("test  Text");
	ASSERT_EQ("test  Text", leftTrim.transform(label3.getText()));

	Label& label4 = SimpleLabel("testText");
	ASSERT_EQ("testText", leftTrim.transform(label4.getText()));

	Label& label5 = SimpleLabel("");
	ASSERT_EQ("", leftTrim.transform(label5.getText()));
}

TEST(LabelTransformationTests, SuccessfulRightTrimTransformation)
{
	TextTransformation& rightTrim = RightTrimTransformation();

	Label& label1 = SimpleLabel("testText  ");
	ASSERT_EQ("testText", rightTrim.transform(label1.getText()));

	Label& label2 = SimpleLabel("  testText");
	ASSERT_EQ("  testText", rightTrim.transform(label2.getText()));

	Label& label3 = SimpleLabel("test  Text");
	ASSERT_EQ("test  Text", rightTrim.transform(label3.getText()));

	Label& label4 = SimpleLabel("testText");
	ASSERT_EQ("testText", rightTrim.transform(label4.getText()));

	Label& label5 = SimpleLabel("");
	ASSERT_EQ("", rightTrim.transform(label5.getText()));
}

TEST(LabelTransformationTests, SuccessfulNormalizeSpaceTransformation)
{
	TextTransformation& normalize = NormalizeSpaceTransformation();

	Label& label1 = SimpleLabel("test    Text");
	ASSERT_EQ("test Text", normalize.transform(label1.getText()));

	Label& label2 = SimpleLabel("  testText");
	ASSERT_EQ(" testText", normalize.transform(label2.getText()));

	Label& label3 = SimpleLabel("testText  ");
	ASSERT_EQ("testText ", normalize.transform(label3.getText()));

	Label& label4 = SimpleLabel("test Text");
	ASSERT_EQ("test Text", normalize.transform(label4.getText()));

	Label& label5 = SimpleLabel("");
	ASSERT_EQ("", normalize.transform(label5.getText()));
}

TEST(LabelTransformationTests, SuccessfulDecorateTransformation)
{
	TextTransformation& decorator = DecorateTransformation();

	Label& label1 = SimpleLabel("testText");
	ASSERT_EQ("-={ testText }=-", decorator.transform(label1.getText()));

	Label& label2 = SimpleLabel("test Text");
	ASSERT_EQ("-={ test Text }=-", decorator.transform(label2.getText()));

	Label& label3 = SimpleLabel("");
	ASSERT_EQ("-={  }=-", decorator.transform(label3.getText()));
}

TEST(LabelTransformationTests, SuccessfulCensorTransformation)
{
	TextTransformation& censor = CensorTransformation("test");

	Label& label1 = SimpleLabel("testText");
	ASSERT_EQ("****Text", censor.transform(label1.getText()));

	Label& label2 = SimpleLabel(" testText");
	ASSERT_EQ(" ****Text", censor.transform(label2.getText()));

	Label& label3 = SimpleLabel("TexttestText");
	ASSERT_EQ("Text****Text", censor.transform(label3.getText()));

	Label& label4 = SimpleLabel("TestText");
	ASSERT_EQ("TestText", censor.transform(label4.getText()));

	Label& label5 = SimpleLabel("");
	ASSERT_EQ("", censor.transform(label5.getText()));
}

TEST(LabelTransformationTests, SuccessfulReplaceTransformation)
{
	TextTransformation& censor = ReplaceTransformation("test", "TESTTSET");

	Label& label1 = SimpleLabel("testText");
	ASSERT_EQ("TESTTSETText", censor.transform(label1.getText()));

	Label& label2 = SimpleLabel(" testText");
	ASSERT_EQ(" TESTTSETText", censor.transform(label2.getText()));

	Label& label3 = SimpleLabel("TexttestText");
	ASSERT_EQ("TextTESTTSETText", censor.transform(label3.getText()));

	Label& label4 = SimpleLabel("TestText");
	ASSERT_EQ("TestText", censor.transform(label4.getText()));

	Label& label5 = SimpleLabel("");
	ASSERT_EQ("", censor.transform(label5.getText()));
}

TEST(LabelTransformationTests, SuccessfulCompositeTransformation)
{
	TextTransformation& composite0 = CompositeTransformation(vector<TextTransformation*>(
		{ new RightTrimTransformation(), new LeftTrimTransformation(), new NormalizeSpaceTransformation() }));
	
	Label& label = SimpleLabel("  test   Test   ");
	ASSERT_EQ("test Test", composite0.transform(label.getText()));

	TextTransformation& composite1 = CompositeTransformation(vector<TextTransformation*>(
		{ new RightTrimTransformation(), new LeftTrimTransformation(), new NormalizeSpaceTransformation(), 
		new CapitalizeTransformation(), new CensorTransformation("Test")}));
	ASSERT_EQ("**** ****", composite1.transform(label.getText()));
}

TEST(LabelTransformationTests, SuccessfulFlyweightCensorTransformation)
{
	CensorTransformationFactory factory;

	Label& label = SimpleLabel("Test Testing");

	TextTransformation* textTransformation = factory.create("Test");
	ASSERT_EQ("**** ****ing", textTransformation->transform(label.getText()));
	delete textTransformation;

	textTransformation = factory.create("Testing");
	ASSERT_EQ("Test *******", textTransformation->transform(label.getText()));
	delete textTransformation;

	textTransformation = factory.create("Test");
	ASSERT_EQ("**** ****ing", textTransformation->transform(label.getText()));
	delete textTransformation;
}

TEST(LabelDecoratorTests, SingleLabelDecorator)
{
	Label* label = new SimpleLabel("testText");
	label = new Decorator(label, new CapitalizeTransformation());
	ASSERT_EQ("TestText", label->getText());
	delete label;

	label = new SimpleLabel("   testText");
	label = new Decorator(label, new LeftTrimTransformation());
	ASSERT_EQ("testText", label->getText());
	delete label;

	label = new SimpleLabel("testText   ");
	label = new Decorator(label, new RightTrimTransformation());
	ASSERT_EQ("testText", label->getText());
	delete label;

	label = new SimpleLabel("test   Text");
	label = new Decorator(label, new NormalizeSpaceTransformation());
	ASSERT_EQ("test Text", label->getText());
	delete label;

	label = new SimpleLabel("testText");
	label = new Decorator(label, new DecorateTransformation());
	ASSERT_EQ("-={ testText }=-", label->getText());
	delete label;

	label = new SimpleLabel("testText");
	label = new Decorator(label, new CensorTransformation("test"));
	ASSERT_EQ("****Text", label->getText());
	delete label;

	label = new SimpleLabel("testText");
	label = new Decorator(label, new ReplaceTransformation("test", "TSET"));
	ASSERT_EQ("TSETText", label->getText());
	delete label;

	label = new SimpleLabel("   Test   Text   ");
	label = new Decorator(label, new CompositeTransformation({
			new LeftTrimTransformation(), 
			new RightTrimTransformation(), 
			new NormalizeSpaceTransformation()}));
	ASSERT_EQ("Test Text", label->getText());
	delete label;
}

TEST(LabelDecoratorTests, MultipleLabelDecorator)
{
	Label* label = new SimpleLabel("  test    Text  ");
	label = new Decorator(label, new LeftTrimTransformation());
	label = new Decorator(label, new RightTrimTransformation());
	label = new Decorator(label, new NormalizeSpaceTransformation());
	label = new Decorator(label, new CapitalizeTransformation());
	ASSERT_EQ("Test Text", label->getText());
	delete label;

	label = new SimpleLabel("testText");
	label = new Decorator(label, new ReplaceTransformation("test", "tset"));
	label = new Decorator(label, new CensorTransformation("se"));
	label = new Decorator(label, new ReplaceTransformation("Text", " teeexxxt"));
	label = new Decorator(label, new ReplaceTransformation("eeexxx", "**"));
	label = new Decorator(label, new DecorateTransformation());
	ASSERT_EQ("-={ t**t t**t }=-", label->getText());
	delete label;

	label = new SimpleLabel("  test    Text  ");
	label = new Decorator(label, new LeftTrimTransformation());
	label = new Decorator(label, new RightTrimTransformation());
	label = new Decorator(label, new NormalizeSpaceTransformation());
	label = new Decorator(label, new CapitalizeTransformation());
	label = new Decorator(label, new ReplaceTransformation("Test", "tset"));
	label = new Decorator(label, new CensorTransformation("se"));
	label = new Decorator(label, new ReplaceTransformation("Text", "teeexxxt"));
	label = new Decorator(label, new ReplaceTransformation("eeexxx", "**"));
	label = new Decorator(label, new DecorateTransformation());
	ASSERT_EQ("-={ t**t t**t }=-", label->getText());
	delete label;

	label = new SimpleLabel("  test    Text  ");
	label = new Decorator(label, new CompositeTransformation({
			new LeftTrimTransformation(),
			new RightTrimTransformation(),
			new NormalizeSpaceTransformation(),
			new CapitalizeTransformation()
		}));
	label = new Decorator(label, new CompositeTransformation({
			new ReplaceTransformation("Test", "tset"),
			new CensorTransformation("se"),
			new ReplaceTransformation("Text", "teeexxxt"),
			new ReplaceTransformation("eeexxx", "**"),
			new DecorateTransformation()
		}));
	ASSERT_EQ("-={ t**t t**t }=-", label->getText());
	delete label;

	CensorTransformationFactory factory;
	label = new SimpleLabel("  test    Texting   Text  ");
	label = new Decorator(label, new CompositeTransformation({
			new LeftTrimTransformation(),
			new RightTrimTransformation(),
			new NormalizeSpaceTransformation()
		}));
	label = new Decorator(label, factory.create("test"));
	label = new Decorator(label, factory.create("Texting"));
	label = new Decorator(label, factory.create("Text"));

	ASSERT_EQ("**** ******* ****", label->getText());
	delete label;
}

TEST(LabelDecoratorTests, SingleRandomDecorator)
{
	vector<TextTransformation*> transformations = {
		new CapitalizeTransformation(),
		new LeftTrimTransformation(),
		new RightTrimTransformation(),
		new NormalizeSpaceTransformation(),
		new DecorateTransformation(),
		new CensorTransformation("test"),
		new ReplaceTransformation("test", "TSET")
	};

	mt19937 rng(1234);
	uniform_int_distribution<int> dist(0, transformations.size() - 1);

	Label* label = new SimpleLabel("  test  Text  ");
	label = new RandomDecorator(label, transformations, 1234);
	for (int i = 0; i < 1000; i++)
	{
		ASSERT_EQ(transformations[dist(rng)]->transform("  test  Text  "), label->getText());
	}
	delete label;
}

TEST(LabelDecoratorTests, RemoveDecorator)
{
	Label* label = new SimpleLabel("  test    Text  ");
	label = new Decorator(label, new LeftTrimTransformation());
	label = new Decorator(label, new RightTrimTransformation());
	label = new Decorator(label, new NormalizeSpaceTransformation());
	label = new Decorator(label, new CapitalizeTransformation());
	label = new Decorator(label, new ReplaceTransformation("Test", "tset"));
	label = new Decorator(label, new CensorTransformation("se"));
	

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR);
	ASSERT_EQ("tset Text", label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::NORMALIZE_SPACE);
	ASSERT_EQ("tset    Text", label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::LEFT_TRIM);
	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::RIGHT_TRIM);
	ASSERT_EQ("  test    Text  ", label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CAPITALIZE);
	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::REPLACE);
	ASSERT_EQ("  test    Text  ", label->getText());

	ASSERT_THROW(label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR),
		std::invalid_argument);

	delete label;
}

TEST(LabelDecoratorTests, RemoveRandomDecorator)
{
	vector<TextTransformation*> transformations0 = {
		new CapitalizeTransformation(),
		new CensorTransformation("test"),
		new ReplaceTransformation("test", "TSET")
	};
	mt19937 rng0(1000);
	uniform_int_distribution<int> dist0(0, transformations0.size() - 1);

	vector<TextTransformation*> transformations1 = {
		new LeftTrimTransformation(),
		new RightTrimTransformation()
	};
	mt19937 rng1(1001);
	uniform_int_distribution<int> dist1(0, transformations1.size() - 1);

	vector<TextTransformation*> transformations2 = {
		new NormalizeSpaceTransformation()
	};
	mt19937 rng2(1010);
	uniform_int_distribution<int> dist2(0, transformations2.size() - 1);

	Label* label = new SimpleLabel("  test  Text  ");
	label = new RandomDecorator(label, transformations0, 1000);
	label = new RandomDecorator(label, transformations1, 1001);
	label = new RandomDecorator(label, transformations2, 1010);

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::NORMALIZE_SPACE);
	string temp = "  test  Text  ";
	temp = transformations0[dist0(rng0)]->transform(temp);
	temp = transformations1[dist1(rng1)]->transform(temp);
	ASSERT_EQ(temp, label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR);
	temp = "  test  Text  ";
	temp = transformations1[dist1(rng1)]->transform(temp);
	ASSERT_EQ(temp, label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::RIGHT_TRIM);
	temp = "  test  Text  ";
	ASSERT_EQ(temp, label->getText());

	ASSERT_THROW(label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR), 
		std::invalid_argument);
	
	delete label;
}

TEST(LabelDecoratorTests, RemoveDecoratorWithCompositeTransformation)
{
	Label* label = new SimpleLabel("  test    Text  ");
	label = new Decorator(label, new CompositeTransformation({
			new LeftTrimTransformation(),
			new RightTrimTransformation(),
			new NormalizeSpaceTransformation(),
			new CapitalizeTransformation()
		}));
	label = new Decorator(label, new CompositeTransformation({
			new ReplaceTransformation("Test", "tset"),
			new CensorTransformation("se"),
			new ReplaceTransformation("Text", "teeexxxt"),
			new ReplaceTransformation("eeexxx", "**"),
			new DecorateTransformation()
		}));


	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR);
	ASSERT_EQ("Test Text", label->getText());

	label = BaseDecorator::removeDecoratorFrom(label, TransformationType::NORMALIZE_SPACE);
	ASSERT_EQ("  test    Text  ", label->getText());

	ASSERT_THROW(label = BaseDecorator::removeDecoratorFrom(label, TransformationType::CENSOR),
		std::invalid_argument);

	delete label;
}