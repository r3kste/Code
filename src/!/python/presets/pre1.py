import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#!pip install lets-plot -U
import lets_plot as lplt



from sklearn.linear_model import LinearRegression as LinReg
from sklearn.linear_model import LogisticRegression as LogReg
from sklearn.preprocessing import PolynomialFeatures as PolyFts
from sklearn.metrics import mean_squared_error as mse, r2_score



from sklearn.utils import shuffle
from sklearn.metrics import accuracy_score 
from sklearn.model_selection import train_test_split as tts
from sklearn.preprocessing import StandardScaler
from sklearn import datasets
import math

from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB