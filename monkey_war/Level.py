from Properties import Atack
from Properties import Health
from Map import Map
from Creature import Creature

def sth_happens():
    nothing = 'nothing'
init_value = 'nothing'

class Level:
    number = init_value
    resources_part = init_value
    boss_part = init_value
    is_passed = init_value

    def start_resources_part():
        sth_happens()

    def start_boss_part():
        sth_happens()

class Resources_part:
    level_map = init_value
    time = init_value

    def set_map(new_map):
        sth_happens()
    def start_collecting():
        sth_happens()

class Boss_part():
    boss = init_value

    def we_win_the_fight():
        sth_happens()
        #return True/False