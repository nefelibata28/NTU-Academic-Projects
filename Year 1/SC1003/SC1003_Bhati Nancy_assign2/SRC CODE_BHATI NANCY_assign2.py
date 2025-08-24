#this is being converted in .py format through jupyter notebook.





#!/usr/bin/env python


# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')
import datetime
import seaborn as sb



# In[2]:


a=pd.read_csv("C:\\Users\\Nancy\\OneDrive\\Documents\\sem2\\sc1003\\project2\\CAC40.csv");
b=pd.read_excel("C:\\Users\\Nancy\\OneDrive\\Documents\\sem2\\sc1003\\project2\\SPY_2016_2021.xlsx");
c=pd.read_csv("C:\\Users\\Nancy\\OneDrive\\Documents\\sem2\\sc1003\\project2\\FTSE100.csv");


# In[4]:


a.head()


# In[4]:


b.head()


# In[5]:


c.head()


# In[6]:


#removing columns from CAC40
a=a.drop(labels=['Open', 'High', 'Low', 'Volume', 'Adj Close'], axis=1)
a.head()


# In[7]:


b.head()


# In[8]:


#removing columns from FTSE100

c=c.drop(labels=[' Open', ' High', ' Low'],axis=1)
c.head()


# In[9]:


c.columns #to check columns


# In[10]:


#plot chart
plt.style.use('seaborn-muted')
plt.plot(a.Close)
plt.show()
#plot chart
plt.style.use('seaborn-muted')
plt.plot(b.Close)
plt.show()
#plot chart
c[" Close"].plot()
plt.show


# In[ ]:





# In[ ]:





# # Generality of code
# It allows user to select which financial excel data file to be used 

# In[5]:


excel_file=input()


# In[6]:


if excel_file=='1':
    print("CAC40")
    print(a)
    df=a
elif excel_file=='2':
    print("SPY_2016_2021")
    print(b)
    df=b
elif excel_file=='3':
    print("FTSE 100")
    print(c)
    df=c
else:
    print("choose correct file")


# In[7]:


df.info()
df.head()
df


# In[8]:


#plot chart
plt.style.use('seaborn-muted')
plt.plot(a.Close)
plt.show()


# In[9]:


#calculate daily return
STARTING_BALANCE=1000000 #initial capital
df['Return'] = df.Close / df.Close.shift(1)
df.Return.iat[0] = 1
df['Bench_Bal'] = STARTING_BALANCE * df.Return.cumprod()

df


# In[10]:


#calculate drawdown(calculatoing how much is dropped)
df['Bench_Peak'] = df.Bench_Bal.cummax()
df['Bench_DD'] = df.Bench_Bal - df.Bench_Peak

bench_dd = round((df.Bench_DD / df.Bench_Peak).min() * 100, 2)

bench_dd #will print worst drop down


# In[11]:


#calculating MACD
SEMA = df.Close.ewm(span = 12, adjust=False).mean()
LEMA = df.Close.ewm(span = 26, adjust=False).mean()

macd = SEMA - LEMA
signal = macd.ewm(span = 9, adjust=False).mean()
histogram=macd-signal
print(macd)
print(signal)
print(histogram)
print("the shorter term  EMA is",SEMA)
print("the longer tern EMA is",LEMA)


# In[12]:


plt.figure()

#create subplot for price data
plt.subplot(211)
plt.plot(df.Close)

#create subplot for MACD
plt.subplot(212)
plt.plot(macd, color = 'y')
plt.plot(signal, color = 'g')

#show plot
plt.show()


# In[13]:


#add column for entries (long when macd line above signal line. buy situation) )
df["macd"]=macd
df["signal"]=signal
df['histogram']=macd-signal


df['Buy_the_stock'] = macd > signal
df["sell_the_stock"]=signal>macd

df.tail()


# In[14]:


w=pd.DataFrame(df[["Close","macd","signal","histogram"]])
w.head()


# In[15]:


plt.figure()

#create subplot for price data
plt.subplot(211)
plt.plot(df.Close)

#create subplot for MACD
plt.subplot(212)
plt.plot(macd, color = 'y')
plt.plot(signal, color = 'g')

#show plot
plt.show()


# In[16]:


w.hist()


# In[17]:


#calculating system return and balance
df['Sys_Ret'] = np.where(df.Buy_the_stock.shift(1) == True, df.Return, 1)

df['Sys_Bal'] = STARTING_BALANCE * df.Sys_Ret.cumprod()
df


# In[18]:


#calculating system drawdown
df['Sys_Peak'] = df.Sys_Bal.cummax()
df['Sys_DD'] = df.Sys_Bal - df.Sys_Peak

sys_dd = round((df.Sys_DD / df.Sys_Peak).min() * 100, 2)

sys_dd


# In[ ]:





# In[19]:


#annual wise return and drawdowns
#calculate metrics
#define backtest range
START = datetime.datetime(2000, 1, 1)
END = datetime.datetime(2020, 1, 1)
Years = (END - START).days / 365.25
bench_return = round(((df.Bench_Bal[1]/df.Bench_Bal[0]) - 1) * 100, 2)
bench_cagr = round(((((df.Bench_Bal[1]/df.Bench_Bal[0])**(1/Years))-1)*100), 2)
sys_ret = round(((df.Sys_Bal[1]/df.Sys_Bal[0]) - 1) * 100, 2)
sys_cagr = round(((((df.Sys_Bal[1]/df.Sys_Bal[0])**(1/Years))-1)*100), 2)

print(f'Benchmark Total return: {bench_return}%')
print(f'Benchmark CAGR: {bench_cagr}%')
print(f'Benchmark DD: {bench_dd}%')
print('')
print(f'System Total return: {sys_ret}%')
print(f'System CAGR: {sys_cagr}%')
print(f'System DD: {sys_dd}%')


# In[20]:


plt.plot(df.Bench_Bal)
plt.plot(df.Sys_Bal)

plt.show()


# In[21]:


ax1 = plt.subplot2grid((8,1), (0,0), rowspan = 5, colspan = 1)
ax2 = plt.subplot2grid((8,1), (5,0), rowspan = 3, colspan = 1)

ax1.plot(df['Close'], color = 'green', linewidth = 1.5, label = 'close')


ax1.legend()
ax1.set_title('DF MACD SIGNALS')
ax2.plot(df['macd'], color = 'red', linewidth = 1.5, label = 'MACD')
ax2.plot(df['signal'], color = 'skyblue', linewidth = 1.5, label = 'SIGNAL')

for i in range(len(df)):
    if str(df['histogram'][i])[0] == '-':
        ax2.bar(df.index[i],df['histogram'][i], color = '#ef5350')
    else:
        ax2.bar(df.index[i], df['histogram'][i], color = '#26a69a')
        
plt.legend(loc = 'lower right')
plt.show()


# In[22]:



def plot_macd( macd, signal, hist):
    ax1 = plt.subplot2grid((9,1), (0,0), rowspan = 5, colspan = 1)
    ax2 = plt.subplot2grid((8,1), (5,0), rowspan = 3, colspan = 1)

    ax1.plot('Close',color='red',linewidth=1.5,label='Close')
    ax2.plot(macd, color = 'grey', linewidth = 1.5, label = 'MACD')
    ax2.plot(signal, color = 'skyblue', linewidth = 1.5, label = 'SIGNAL')

    for i in range(len('Close')):
        if str(hist[i])[0] == '-':
            ax2.bar(df.index[i], hist[i], color = '#ef5350')
        else:
            ax2.bar(df.index[i], hist[i], color = '#26a69a')

    plt.legend(loc = 'lower right')

plot_macd( df['macd'], df['signal'], df['histogram'])


# In[ ]:





# In[26]:



#total number of trades made using MACD

total=len("Close")
print(total)
buy=len("Buy_the_stock")
print(buy)


# In[24]:


df["Sys_Ret"]


# In[25]:


#average return per trade
#total sum
sumtotal=df["Sys_Ret"].sum()
print (sumtotal)

#total length
length=len(df["Sys_Ret"])
print(length)
#average
avg=sumtotal/length
print(avg)


# In[ ]:





# In[32]:


df.sum(axis=1,skipna=True)


# In[56]:


#relative gain
df["Sys_Ret"]


# In[62]:


#realtive loss
df["Sys_DD"]


# In[ ]:




