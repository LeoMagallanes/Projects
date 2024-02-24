## Overview

The objective of the project is to predict climbing grades based on different features.
We aim to develop a predictive model that estimates climbing grades based on various climber attributes.

## Data

The dataset used was obtained from https://www.kaggle.com/datasets/jordizar/climb-dataset

It contains 3 different archives.
1. **routes_rated.csv**. It has 9 features such as country and grade_mean.
2. **grades_conversion_table.csv**. It contains 2 features; grade_id and grade_fra. This archive is used to convert from the data of the dataset to the french grading system.
3. **climber_df.csv**. This is where the most important features are such as height, weight, age, years climbing and maximum grade climbed. It has 16 features.

## Analysis

Importance:
Accurate climbing grade predictions can enhance safety by helping climbers choose routes that match their skill level. Novice climbers can avoid overly challenging routes, reducing the risk of accidents, while experienced climbers can find routes that provide the appropriate level of challenge to further develop their skills
It can also be used for route recommendations, competition and event planning, research and analysis. Climbing grade predictions can serve as valuable data for researchers studying climbing trends and performance over time.


Challenges:

It is hard to have an accurate prediction with the information on the dataset, I think that in order to have a valuable grade prediction we should also have information about the capabilities of the climber such as finger strength tests, pull strength test and other various tests.
Given this limitations this predictions should be taken with caution.

## Machine Learning Models

These are the 5 different regressors model that we used for predicting.

**SVC**: Support Vector Classifier is a supervised learning algorithm used for classification tasks.

**RandomForestRegressor**: RandomForestRegressor is an ensemble learning method based on decision trees.

**MLPRegressor**: Multi-Layer Perceptron Regressor is a type of artificial neural network commonly used for regression and classification tasks.

**KNeighborsRegressor**: K-Nearest Neighbors Regressor K-Nearest Neighbors is a simple yet effective algorithm for regression tasks. 

**LinearRegression**: Linear Regression Linear Regression is one of the most basic and widely used regression algorithms.  It models the relationship between the target variable and predictor variables as a linear equation.



## Model Training



## Results

| Model  | MAE  | MSE  | R^2  |
| ------------ | ------------ | ------------ | ------------ |
|SVC   |9.48   |147.81   |-0.55   |
|Random Forest Regressor   |1.65   |5.28   |0.94   |
|MLP Regressor   |4.00   |27.79   |0.71   |
|K Neighbors Regressor   |8.61   |112.08   |-0.18   |
|Linear Regressor   |3.82   |24.02   |0.75   |
We evaluated the models with the metric Minimun Absolut Error(MAE), Minimim Square Error(MSE) and the metric R^2 score.

From this table we can see that the best performing model was the Random Forest Regressor.

## Dependencies

You can run this code by simply using google colaboratory or follow the next instructions.

To run this project, you'll need to have the following Python packages and libraries installed:

- `scikit-learn`: Machine learning library for model building and evaluation.
- `pandas`: Data manipulation and analysis tool for handling datasets.
- `numpy`: Library for numerical operations and efficient array handling.
- `matplotlib`: Data visualization library for creating plots and charts.
- `seaborn`: Statistical data visualization library, built on top of matplotlib.
- `joblib`: Library for saving and loading machine learning models.
- `scipy`: Scientific computing library for advanced data analysis.
- `jupyter`: Interactive computing environment for data exploration and experimentation.

You can install these dependencies using `pip` and the provided `requirements.txt` file:

```bash
pip install -r requirements.txt
```

## Contributors
This project was developed by Javier Fernando Romo Urrutia and Leonardo Alejandro Magallanes Tejada as a part of a final project in our machine learning class.

## Acknowledgments
The original dataset was taken from the page [8a.nu](https://www.8a.nu/ "8a.nu") by David Cohen and then we used the 3 tables uploaded by [Jordi Zaragoza.](http://https://www.kaggle.com/datasets/jordizar/climb-dataset "Jordi Zaragoza")
##Contact Information
0236887@up.edu.mx

## Conclusion
After thorough evaluation and comparative analysis of the machine learning models, we have chosen the Random Forest Regressor as our preferred model for predicting climbing grades. This decision is backed by the model's outstanding performance in terms of key metrics such as Mean Absolute Error (MAE), Mean Squared Error (MSE), and the coefficient of determination (R²).

Our GitHub repository provides access to the code, data, and detailed documentation, allowing users to explore the model, replicate our findings, and contribute to further improvements. We believe that this project not only advances our understanding of climbing grade prediction but also serves as a valuable resource for the climbing community and machine learning enthusiasts alike.

We encourage you to dive into our repository, experiment with the model, and join us in the quest to enhance climbing grade predictions and promote safer and more enjoyable climbing experiences.

Also for a more accurate precision we would need more accurate and robust data. Data from each climber like performance evaluations, evaluate the maximum grip strength in a specified and standarized hold, maximum pull up weight and other important features. We can't prove that the data in the dataset is true, because in the 8a.nu each climber can upload any route without proof that he indeed climbed the route. 
