package bg.sofia.uni.fmi.mjt.query_utils;

public class TestRequestsRepository {
    public static final String PAGE_ONE_TEST_RESPONSE = """
        {
          "from": 1,
          "to": 20,
          "count": 10000,
          "_links": {
            "next": {
              "href": "https://api.edamam.com/api/recipes/v2?q=chicken&app_key=test_key&field=label&field=healthLabels&field=mealType&_cont=CHcVQBtNNQphDmgVQntAEX4BYldtAAIES2VJAGcVZV16AAYDUXlSCmpFNVEiAgQPRmxIBmsRagN0DVEEEDFCBTQUZVcgB1IVLnlSVSBMPkd5BgNK&type=public&app_id=test_id",
              "title": "Next page"
            }
          },
          "hits": [
            {
              "recipe": {
                "label": "Chicken Vesuvio",
                "healthLabels": [
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Paprikash",
                "healthLabels": [
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Baked Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Keto-Friendly",
                  "Paleo",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "FODMAP-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Kreplach (Chicken Dumplings)",
                "healthLabels": [
                  "Mediterranean",
                  "Dairy-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Stew",
                "healthLabels": [
                  "Paleo",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Catalan Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Keto-Friendly",
                  "Paleo",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "No oil added",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Persian Chicken",
                "healthLabels": [
                  "Gluten-Free",
                  "Wheat-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken cacciatore",
                "healthLabels": [
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Roast Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Kidney-Friendly",
                  "Keto-Friendly",
                  "Paleo",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free",
                  "Kosher",
                  "Immuno-Supportive"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Crêpes",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Smothered Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Dairy-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Hash",
                "healthLabels": [
                  "Dairy-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Poofs",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Feet Stock",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Low Potassium",
                  "Kidney-Friendly",
                  "Keto-Friendly",
                  "Paleo",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Soup",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Keto-Friendly",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Pie",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Chicken Enchiladas",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "Sulfite-Free"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Roast Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Keto-Friendly",
                  "Paleo",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Citrus Roasted Chicken",
                "healthLabels": [
                  "Paleo",
                  "Mediterranean",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Wheat-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "Alcohol-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            },
            {
              "recipe": {
                "label": "Margarita Chicken",
                "healthLabels": [
                  "Sugar-Conscious",
                  "Keto-Friendly",
                  "Paleo",
                  "Dairy-Free",
                  "Gluten-Free",
                  "Egg-Free",
                  "Peanut-Free",
                  "Tree-Nut-Free",
                  "Soy-Free",
                  "Fish-Free",
                  "Shellfish-Free",
                  "Pork-Free",
                  "Red-Meat-Free",
                  "Crustacean-Free",
                  "Celery-Free",
                  "Mustard-Free",
                  "Sesame-Free",
                  "Lupine-Free",
                  "Mollusk-Free",
                  "No oil added",
                  "Sulfite-Free",
                  "Kosher"
                ],
                "mealType": [
                  "lunch/dinner"
                ]
              }
            }
          ]
        }
        """;
}
