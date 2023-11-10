# Project 2
Project 2 comprises three different sets of tasks. 

In the first part, Classification with Numerical Data, the project involves loading and preprocessing train and test datasets. The target variable is "label," and feature histograms are visualized. A Logistic Regression classifier is trained using GridSearchCV, and then two other low-level classifiers are chosen and evaluated with grid search and cross-validation. Random Forest and Gradient Boosting classifiers are also employed, and feature importance is visualized.

The second part, Classification with Text Data, involves loading and processing text data from "cover train.csv" and "cover test.csv." The content from "title" and "description" columns is combined and transformed into a Bag-of-Words representation with TF-IDF scaling. A classifier is trained, and its performance is evaluated on the train and test sets.

In the final part, Classification with Image Data, image data from "cover train.npz" and "cover test.npz" is loaded and labeled. PCA is applied to the dataset, followed by training a classifier, and evaluating its performance on the train and test sets.