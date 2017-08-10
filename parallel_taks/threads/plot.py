import pandas as pd
import matplotlib.pyplot as plt

def load(name_file):
    df = pd.read_csv(name_file, names=["NUM_THREADS", "TIME"])
    return df

def plot(df):
    num_threads =  df["NUM_THREADS"]
    time= df["TIME"]
    plt.plot(num_threads,time, 'b-', ms=1)
    plt.plot(num_threads,time, 'g.', ms=10)
    for a,b in zip(num_threads,time):
        plt.text(a, b, str(b))
        pass
    plt.show()
    

if __name__ == "__main__":
    name_file = 'times2.csv'
    df = load(name_file) 
    plot(df)
