#include "pch.h"
#include <fstream>
#include "Figures/Triangle.h"
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/FigureFactories/StreamFigureFactory.h"
#include "Figures/FigureFactories/RandomFigureFactory.h"
#include "Figures/FigureFactories/AbstractFactory.h"

namespace FigureTests
{
	namespace TriangleTests
	{
		TEST(TriangleTests, Constructor)
		{
			ASSERT_THROW(new Triangle(-5, 5, 5), std::invalid_argument);
			ASSERT_THROW(new Triangle(5, -5, 5), std::invalid_argument);
			ASSERT_THROW(new Triangle(5, 5, -5), std::invalid_argument);

			ASSERT_THROW(new Triangle(0, 5, 5), std::invalid_argument);
			ASSERT_THROW(new Triangle(5, 0, 5), std::invalid_argument);
			ASSERT_THROW(new Triangle(5, 5, 0), std::invalid_argument);

			ASSERT_THROW(new Triangle(1, 2, 4), std::invalid_argument);
		}

		TEST(TriangleTests, GetPerimeter)
		{
			Triangle t1(5, 4, 3);
			Triangle t2(3.5, 1.32, 2.34);
			Triangle t3(2.1, 3.0, 1.22);

			EXPECT_NEAR(t1.getPerimeter(), 12, 0.0);
			EXPECT_NEAR(t2.getPerimeter(), 7.16, 0.03);
			EXPECT_NEAR(t3.getPerimeter(), 6.32, 0.03);
		}

		TEST(TriangleTests, Equal)
		{
			{
				Triangle t1(3, 4, 5);
				Triangle t2(3, 4, 5);
				EXPECT_EQ(t1, t2);
			}

			{
				Triangle t1(0.00001, 0.000001, 0.00001);
				Triangle t2(0.00001, 0.000001, 0.00001);
				EXPECT_EQ(t1, t2);
			}
		}

		TEST(TriangleTests, NotEqual)
		{
			{
				Triangle t1(3, 4, 5);
				Triangle t2(3, 4, 6);
				EXPECT_NE(t1, t2);
			}

			{
				Triangle t1(3, 4, 5);
				Triangle t2(3, 3, 5);
				EXPECT_NE(t1, t2);
			}

			{
				Triangle t1(2, 4, 5);
				Triangle t2(4, 3, 5);
				EXPECT_NE(t1, t2);
			}

			{
				Triangle t1(4, 5, 6);
				Triangle t2(5, 6, 7);
				EXPECT_NE(t1, t2);
			}
		}

		TEST(TriangleTests, CloneProducesEqualObject)
		{
			Triangle t1(3, 4, 5);
			unique_ptr<Figure> temp = t1.clone();
			Triangle& t2 = dynamic_cast<Triangle&>(*temp);
			EXPECT_EQ(t1, t2);
		}

		TEST(TriangleTests, ToString)
		{
			Triangle t(3, 4, 5);
			ASSERT_EQ(t.toString(), "triangle 3 4 5");
		}
	}

	namespace CircleTests
	{
		TEST(CircleTests, Constructor)
		{
			ASSERT_THROW(new Circle(-1), std::invalid_argument);
			ASSERT_THROW(new Circle(0), std::invalid_argument);
		}

		TEST(CircleTests, GetPerimeter)
		{
			Circle c1(5);
			Circle c2(4.5);
			Circle c3(2.654);

			EXPECT_NEAR(c1.getPerimeter(), 31.416, 0.0001);
			EXPECT_NEAR(c2.getPerimeter(), 28.2743, 0.0001);
			EXPECT_NEAR(c3.getPerimeter(), 16.6756, 0.0001);
		}

		TEST(CircleTests, Equal)
		{
			{
				Circle c1(4);
				Circle c2(4);
				EXPECT_EQ(c1, c2);
			}

			{
				Circle c1(4);
				Circle c2(4);
				EXPECT_EQ(c1, c2);
			}
		}

		TEST(CircleTests, NotEqual)
		{
			Circle c1(2);
			Circle c2(3);
			EXPECT_NE(c1, c2);
		}

		TEST(CircleTests, CloneProducesEqualObject)
		{
			Circle c1(4);
			unique_ptr<Figure> temp = c1.clone();
			Circle& c2 = dynamic_cast<Circle&>(*temp);
			EXPECT_EQ(c1, c2);
		}

		TEST(CircleTests, ToString)
		{
			Circle c(5);
			ASSERT_EQ(c.toString(), "circle 5");
		}
	}

	namespace RectangleTests
	{
		TEST(RectangleTests, Constructor)
		{
			ASSERT_THROW(new Rectangle(-1, 5), std::invalid_argument);
			ASSERT_THROW(new Rectangle(0, 5), std::invalid_argument);
			ASSERT_THROW(new Rectangle(5, -1), std::invalid_argument);
			ASSERT_THROW(new Rectangle(5, 0), std::invalid_argument);
		}

		TEST(RectangleTests, GetPerimeter)
		{
			Rectangle r1(5, 4);
			Rectangle r2(2.5, 4.5);
			Rectangle r3(2.33, 6.12);

			EXPECT_NEAR(r1.getPerimeter(), 18, 0.0001);
			EXPECT_NEAR(r2.getPerimeter(), 14, 0.0001);
			EXPECT_NEAR(r3.getPerimeter(), 16.9, 0.0001);
		}

		TEST(RectangleTests, Equal)
		{
			{
				Rectangle r1(4, 5);
				Rectangle r2(4, 5);
				EXPECT_EQ(r1, r2);
			}
			{
				Rectangle r1(0.00001, 5);
				Rectangle r2(0.00001, 5);
				EXPECT_EQ(r1, r2);
			}
		}

		TEST(RectangleTests, NotEqual)
		{
			{
				Rectangle r1(4, 5);
				Rectangle r2(4, 4);
				EXPECT_NE(r1, r2);
			}

			{
				Rectangle r1(4, 5);
				Rectangle r2(3, 5);
				EXPECT_NE(r1, r2);
			}
		}

		TEST(RectangleTests, CloneProducesEqualObject)
		{
			Rectangle r1(4, 5);
			unique_ptr<Figure> temp = r1.clone();
			Rectangle& r2 = dynamic_cast<Rectangle&>(*temp);
			EXPECT_EQ(r1, r2);
		}

		TEST(RectangleTests, ToString)
		{
			Rectangle r(4, 5);
			ASSERT_EQ(r.toString(), "rectangle 4 5");
		}
	}
}

namespace FactoryTests
{
	namespace FigureFactoryTests
	{
		TEST(FigureFactoryTests, SuccessfulTriangleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			Triangle t2(4, 5, 6);
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("triangle 4 5 6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("   triangle 4 5 6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("triangle   4 5 6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("triangle 4   5 6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("triangle 4 5    6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("   triangle    4   5    6");
				Triangle& t1 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
		}

		TEST(FigureFactoryTests, UnsuccessfulTriangleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			EXPECT_THROW(figureFactory.createFigure("triaagle 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("Triangle 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("TriANgle 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triANgle 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 5 6   "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle a 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 a 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 5 a"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle ABc 5 a"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 bcda 3"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 5 "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 4 "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 2 3 4 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("triangle 2 3 4 5   "), std::invalid_argument);
		}

		TEST(FigureFactoryTests, SuccessfulCircleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			Circle c2(4);
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("circle 4");
				Circle& c1 = dynamic_cast<Circle&>(*ptr);
				ASSERT_EQ(c1, c2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("   circle 4");
				Circle& c1 = dynamic_cast<Circle&>(*ptr);
				ASSERT_EQ(c1, c2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("circle    4");
				Circle& c1 = dynamic_cast<Circle&>(*ptr);
				ASSERT_EQ(c1, c2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("    circle   4");
				Circle& c1 = dynamic_cast<Circle&>(*ptr);
				ASSERT_EQ(c1, c2);
			}
		}

		TEST(FigureFactoryTests, UnsuccessfulCircleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			EXPECT_THROW(figureFactory.createFigure("ciircle 4"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("Circle 4"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("CirCLe 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle 4   "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle a"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle ABc"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle 4 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle 4   "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle 2 3 4"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("circle 2 3 4   "), std::invalid_argument);
		}

		TEST(FigureFactoryTests, SuccessfulRectangleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			Rectangle r2(4, 5);
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("rectangle 4 5");
				Rectangle& r1 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("   rectangle 4 5");
				Rectangle& r1 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("rectangle   4 5");
				Rectangle& r1 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("rectangle 4   5");
				Rectangle& r1 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
			{
				unique_ptr<Figure> ptr = figureFactory.createFigure("   rectangle    4   5");
				Rectangle& r1 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
		}

		TEST(FigureFactoryTests, UnsuccessfulRectangleCreation)
		{
			FigureFactory& figureFactory = StreamFigureFactory(std::cin);
			EXPECT_THROW(figureFactory.createFigure("rectaangle 4 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("Rectangle 4 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("RecTaNgle 4 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("reCTangle 4 5 6"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 4 5   "), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle a 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 4 a"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle ABc 5"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 4 bcda"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 4"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 2 3 4"), std::invalid_argument);
			EXPECT_THROW(figureFactory.createFigure("rectangle 2 3 4   "), std::invalid_argument);
		}
	}

	namespace StreamFigureFactoryTests
	{
		TEST(StreamFigureFactoryTests, FigureCreation)
		{
			ifstream fileStream("../FigureManager-Test/TestFigures01.txt");

			StreamFigureFactory factory(std::move(fileStream));
			{
				Triangle t1(3, 4, 5);
				unique_ptr<Figure> ptr = factory.createFigure();
				Triangle& t2 = dynamic_cast<Triangle&>(*ptr);
				ASSERT_EQ(t1, t2);
			}
			{
				Circle c1(4);
				unique_ptr<Figure> ptr = factory.createFigure();
				Circle& c2 = dynamic_cast<Circle&>(*ptr);
				ASSERT_EQ(c1, c2);
			}
			{
				Rectangle r1(4, 5);
				unique_ptr<Figure> ptr = factory.createFigure();
				Rectangle& r2 = dynamic_cast<Rectangle&>(*ptr);
				ASSERT_EQ(r1, r2);
			}
			{
				ASSERT_THROW(unique_ptr<Figure> ptr = factory.createFigure(), std::runtime_error);
			}
		}

		TEST(StreamFigureFactoryTests, InvalidFileToConstructor)
		{
			ifstream fileStream("fake.txt");
			ASSERT_THROW(StreamFigureFactory factory(std::move(fileStream)), std::invalid_argument);
		}
	}

	namespace RandomFigureFactoryTests
	{
		TEST(RandomFigureFactoryTests, FigureCreation)
		{
			const uint32_t TEST_SEED = 1234;
			mt19937 rng;
			rng.seed(TEST_SEED);
			uniform_int_distribution<int> figureDistrib(0, NUMBER_OF_SHAPES-1);
			uniform_real_distribution<double> sideDistrib(0.000001, std::numeric_limits<double>::max());

			RandomFigureFactory factory(TEST_SEED);

			int NUMBER_OF_FIGURES = 1000;
			for (int i = 0; i < NUMBER_OF_FIGURES; i++)
			{
				unique_ptr<Figure> ptr = factory.createFigure();
				ASSERT_NE(ptr, nullptr);

				Figures figure = (Figures)figureDistrib(rng);
				switch (figure)
				{
					case TRIANGLE:
					{
						double a = 0, b = 0, c = 0;
						while (a >= c + b || b >= a + c || c >= a + b)
						{
							a = sideDistrib(rng);
							b = sideDistrib(rng);
							c = sideDistrib(rng);
						}
						Triangle t1(a, b, c);
						Triangle& t2 = dynamic_cast<Triangle&>(*ptr);
						ASSERT_EQ(t1, t2);
					} break;
					case CIRCLE:
					{
						double r;
						r = sideDistrib(rng);
						Circle c1(r);
						Circle& c2 = dynamic_cast<Circle&>(*ptr);
						ASSERT_EQ(c1, c2);
					} break;
					case RECTANGLE:
					{
						double a, b;
						a = sideDistrib(rng);
						b = sideDistrib(rng);
						Rectangle r1(a, b);
						Rectangle& r2 = dynamic_cast<Rectangle&>(*ptr);
						ASSERT_EQ(r1, r2);
					}	break;
				}
			}
		}
	}

	namespace AbstractFactoryTests
	{
		TEST(AbstractFactoryTests, SuccesfulRandomFactoryCreation)
		{
			AbstractFactory factory;
			unique_ptr<FigureFactory> ptr = factory.createFactory("random");
			ASSERT_NO_THROW(RandomFigureFactory& figureFactory = dynamic_cast<RandomFigureFactory&>(*ptr));
		}

		TEST(AbstractFactoryTests, SuccesfulStdinFactoryCreation)
		{
			AbstractFactory factory;
			unique_ptr<FigureFactory> ptr = factory.createFactory("stdin");
			ASSERT_NO_THROW(StreamFigureFactory & figureFactory = dynamic_cast<StreamFigureFactory&>(*ptr));
		}

		TEST(AbstractFactoryTests, SuccesfulFileStreamFactoryCreation)
		{
			AbstractFactory factory;
			unique_ptr<FigureFactory> ptr = factory.createFactory("file ../FigureManager-Test/TestFigures01.txt");
			ASSERT_NO_THROW(StreamFigureFactory & figureFactory = dynamic_cast<StreamFigureFactory&>(*ptr));
		}

		TEST(AbstractFactoryTests, InvalidFactoryCreation)
		{
			AbstractFactory factory;
			ASSERT_THROW(factory.createFactory("fakeFactory"), std::invalid_argument);
		}
	}
}