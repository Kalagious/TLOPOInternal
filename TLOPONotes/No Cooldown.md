def getModifiedRechargeTime(self, av, skillId, ammoSkillId=0): in /pirates/battle/BattleManagerBase.py is a really good function to look at that returns the recharge time as a float. This function could be hook to return zero for certain skill ids. 

It also has an instance recharge parmeter which may be found an modified 
```python
if config.GetBool('instant-skill-recharge', 0):
	return 0.0
```
