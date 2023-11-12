## Title: Exploring the effectiveness of BERT using different pooling strategies on SVM for news classification
### Overview
This project focuses on exploring and comparing different text representation methods for improving news topics classification accuracy. The following sections provide an overview of the project, its structure, and instructions for reproduction.

### Dataset

The dataset used in this project can be found on Kaggle: [AG News Classification Dataset](https://www.kaggle.com/datasets/amananandrai/ag-news-classification-dataset).

### Project Summary
The primary objectives of this project include:

#### Data Cleaning:
Conducted thorough cleaning of the dataset to ensure data quality and consistency.

#### BERT Embeddings:
Utilized BERT to generate embeddings for text data.
Implemented various pooling strategies, including:
CLS Token
Mean Pooling
Max Pooling
Attention Pooling
Mixed Pooling (Average pooling on the first 6 layers, Max pooling on remaining layers)

#### Hyperparameter Tuning for SVM:
Employed grid search to identify optimal hyperparameters for SVM (Support Vector Machine) classifiers.

#### SVM with BERT Embeddings:
Fitted BERT embeddings resulting from different pooling methods to SVM classifiers.
Evaluated and recorded accuracy and F1 score for each embedding approach.

#### TF-IDF Vectors:
Created TF-IDF vectors for the cleaned original data.
Conducted hyperparameter tuning to identify optimal settings for SVM classifiers using TF-IDF vectors.

#### Comparison of Results:
Compared and analyzed the results obtained from SVM classifiers using BERT embeddings and TF-IDF vectors.
Highlighted key findings and insights from the comparative analysis.
