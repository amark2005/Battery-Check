import os 
class calcu:
    def __init__(self):
        self.energy_full=float(os.environ["energy_full"])
        self.energy_full_design=float(os.environ["energy_full_design"])
        self.calcu_health()
    def calcu_health(self):
        self.bat_health=int((self.energy_full/self.energy_full_design)*100)
    def __repr__(self):
        return f"full energy: {self.energy_full} | Full energy by design: {self.energy_full_design} | Battery Health: {self.bat_health}% | "
a=calcu()
print(a)