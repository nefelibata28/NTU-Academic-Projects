# SC4000 – Machine Learning

This folder contains project for **SC4000**. 

## Project - ELO Merchant Category Recommendation
   > As part of the SC4000 Machine Learning course, our team worked on the ELO Merchant Category Recommendation challenge from Kaggle.

## Project Highlights
- Predicting loyalty scores for Elo cardholders using transactional, card, and merchant data.
- Explored multiple machine learning models: Decision Tree, Random Forest, XGBoost, LightGBM, CatBoost.
- Implemented ensemble learning using a neural network meta-learner and multi-head attention mechanism.
- Achieved Kaggle public RMSE of 3.683, ranking 337th.
<img width="743" height="158" alt="image" src="https://github.com/user-attachments/assets/df428899-743a-4647-9bfc-48c0a946ed04" />


## Overview
Elo, one of the largest payment brands in Brazil, partners with merchants to offer promotions to cardholders. This project aims to develop machine learning models that predict customer loyalty scores, enabling personalized recommendations while reducing irrelevant promotions.

The challenge is based on the [Kaggle ELO Merchant Category Recommendation competition](https://www.kaggle.com/competitions/elo-merchant-category-recommendation), with submissions evaluated using Root Mean Squared Error (RMSE).

## Objectives
- Predict customer loyalty scores accurately using provided datasets.
- Explore multiple machine learning and ensemble models for improved performance.
- Perform feature engineering to handle anonymized and normalized datasets.
- Evaluate models using cross-validation and optimize hyperparameters.
- Submit predictions to Kaggle and analyze model performance.

## Dataset Overview
The project uses several datasets provided in the competition:

- train.csv - the training set
- test.csv - the test set
- sample_submission.csv - a sample submission file in the correct format - contains all card_ids you are expected to predict for.
- historical_transactions.csv - up to 3 months' worth of historical transactions for each card_id
- merchants.csv - additional information about all merchants / merchant_ids in the dataset.
- new_merchant_transactions.csv - two months' worth of data for each card_id containing ALL purchases that card_id made at merchant_ids that were not visited in the historical data.

##. Methodology

### 1. Exploratory Data Analysis (EDA)
- Examined feature distributions, correlations, and outliers.
- Identified weak correlation between features and target, highlighting the need for feature engineering.
<img width="550"  alt="image" src="https://github.com/user-attachments/assets/9524fd08-504e-443d-bf40-b5ce496fd204" /> <img width="400"  alt="image" src="https://github.com/user-attachments/assets/c6b8fde0-bd9d-4b24-98ad-89a552227537" />


### 2. Feature Engineering
- Handled null values intelligently using domain knowledge.
- Date splitting and derivation of temporal features.
- One-hot encoding of categorical variables and aggregation by card_id.
- Merged transaction and merchant data to create final training dataset.
<img width="490" alt="image" src="https://github.com/user-attachments/assets/ca65ea4a-3b3c-4a7e-87b4-2b65040bba0b" />


### 3. Model Training & Evaluation
- Models tested: Decision Tree, Random Forest, XGBoost, LightGBM, CatBoost.
- Hyperparameter tuning using GridSearchCV, Optuna, and K-Fold cross-validation.
- Feature importance used to select relevant features for model efficiency.

### 4. Ensemble Learning
- Predictions from base models were stacked using a neural network meta-learner.
- Multi-head attention mechanism applied to improve feature weighting.
- Averaged predictions from multiple neural networks to minimize noise.
  
<img width="400"  alt="image" src="https://github.com/user-attachments/assets/4c22f7e3-21be-4e35-8beb-e0a5d94e42f0" />  <img width="500" alt="image" src="https://github.com/user-attachments/assets/badc938d-b252-4880-ae00-0f4996a1fea6" />


## Deliverables
- [Report](https://drive.google.com/file/d/1_G_O7wRGIhYK5wy6hkq_APybZSa-Q3ul/view?usp=sharing)
- [Video](https://www.youtube.com/watch?v=nK6rqaTp45I&feature=youtu.be)

## Result
<img width="400" alt="image" src="https://github.com/user-attachments/assets/7123c0b7-1711-4c92-822e-f6275f0fef70" />

As final enhancements, we’ve trained with 50 separate neural network models, each with a randomly assigned number of epochs (in multiples of 10) to introduce variance between them.

The predictions were averaged to derive our final prediction, minimising the effect of noise picked up by each meta model. Our score improved to 3.649 (4s.f) on the validation set and 3.683 (4s.f) on Kaggle, which commensurates to 337th place out of 4111 submissions in ELO’s
competition ranking.

## Tools Used
- Programming Language: Python
- Libraries: pandas, numpy, scikit-learn, XGBoost, LightGBM, CatBoost, Optuna, matplotlib, seaborn, TensorFlow/Keras
- IDE: VS Code, Jupyter Notebook

## Key Learnings
- Importance of feature engineering for anonymized datasets.
- Handling outliers and missing values significantly impacts model performance.
- Ensemble learning (stacking models) can outperform individual models.
- Hyperparameter tuning and K-Fold validation reduce overfitting and improve generalization.
- Multi-head attention can improve neural network predictions by focusing on important features.
  
## Notes

- All work was submitted as part of NTU coursework.
- This repository is for academic reference and learning purposes only.
- Please do not plagiarize.


