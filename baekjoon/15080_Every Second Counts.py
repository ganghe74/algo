from datetime import datetime as d;p=d.strptime;x=[p(input(), '%H : %M : %S') for _ in '  '];print((x[1]-x[0]).seconds)