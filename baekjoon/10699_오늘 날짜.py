import datetime
dt = datetime.datetime.now()
if dt.hour > 15:
    dt = datetime.datetime(dt.year, dt.month, dt.day+1)
print("%d-%2d-%d"%(dt.year, dt.month, dt.day))