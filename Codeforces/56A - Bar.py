#!/usr/bin/env python3
n = int(input())
ans = 0
al = ['ABSINTH','BEER','BRANDY','CHAMPAGNE','GIN','RUM','SAKE','TEQUILA','VODKA','WHISKEY','WINE']
while n > 0:
	n -= 1
	s = input()
	try:
		age = int(s)
		if (age < 18):
			ans += 1
	except:
		if s in al:
			ans += 1
print(ans)
