# Bird Species Prediction Website

This GitHub repository contains code for a deep learning model to predict bird species from images and a Streamlit-based web application that utilizes the trained model for real-time predictions.

## Dataset

Before running the code, download the dataset from [Kaggle](https://www.kaggle.com/datasets/gpiosenka/100-bird-species) and place it in the `Datasets/BIRDS450` directory.

## 1. Model Training Code

The training code (`train_and_save_model.py`) uses TensorFlow and Keras to create and train a convolutional neural network (CNN) for bird species classification. Here is a brief overview of the code:

- **Dataset Loading:** The script loads bird images from the specified directory and splits them into training and testing sets.

- **Data Preprocessing:** Images are converted to NumPy arrays, and labels are encoded using `LabelEncoder`. The script also performs one-hot encoding on the labels.

- **Model Architecture:** The CNN model is defined using Keras, consisting of convolutional layers, max-pooling layers, and fully connected layers.

- **Model Pruning:** The script uses TensorFlow Model Optimization for model pruning, reducing model size while maintaining performance.

- **Training:** The model is trained using the training set, and the final pruned model is saved as a TensorFlow Lite model.

## 2. Web Application Code

The web application (`app.py`) is built using Streamlit and allows users to upload images for bird species prediction. Here is a brief overview of the code:

- **Dependencies:** The application uses various Python libraries, including Streamlit, TensorFlow, and PIL.

- **Utility Functions:** Several utility functions handle tasks such as loading the index-to-label dictionary, loading file structures, and predicting bird species probabilities.

- **User Interface:** The Streamlit app provides a user-friendly interface for image uploads and displays predictions along with confidence levels.

- **Example Images:** The app also displays three additional images of the predicted bird species along with links to Wikipedia for further information.

## Instructions for Running the Application

1. Clone the repository: `git clone https://github.com/yourusername/bird-species-prediction.git`
2. Navigate to the project directory: `cd bird-species-prediction`
3. Install dependencies: `pip install -r requirements.txt`
4. Download the dataset from Kaggle and place it in the `Datasets/BIRDS450` directory.
5. Run the Streamlit app: `streamlit run app.py`