import random
import datetime
lastname =['Абрамов', 'Авдеев', 'Агафонов', 'Аксёнов', 'Александров', 'Алексеев', 'Андреев', 'Антонов', 'Артемьев', 'Афанасьев',
    'Баранов', 'Белов', 'Белозёров', 'Белоусов', 'Беляев', 'Беляков', 'Беспалов', 'Бирюков', 'Блинов', 'Блохин', 'Бобров', 'Бобылёв', 'Богданов',
    'Большаков','Борисов', 'Брагин', 'Буров', 'Быков', 'Васильев', 'Веселов', 'Виноградов', 'Вишняков', 'Владимиров', 'Власов', 'Волков',
    'Воробьёв', 'Воронов', 'Воронцов', 'Гаврилов', 'Галкин']
initials = ['А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ж', 'Э', 'И', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Э', 'Ю', 'Я']
cars = ['Audi', 'BMW', 'Ford', 'Honda', 'Hyundai', 'Kia'
        'Daihatsu'
        'Cadillac'
        'ГАЗ'
        'Bugatti'
        'Rover'
        'Haima'

file = open('test.txt', 'w')
count_names = 40
file.write(str(count_names)+'\n')
for i in range(count_names):
    bus_number = random.randint(1, 100)
    now = datetime.datetime.now()
    year = random.randint(2000, now.year)
    print(year)
    mileage = 5000 + 5000*(now.year-year)
    file.write(random.choice(lastname) + ' ' + random.choice(initials) + ' ' + random.choice(initials) +
                ' ' + str(bus_number) + ' ' + 'М'+str(bus_number) + ' ' + random.choice(cars) + ' ' + str(year) + ' ' + str(mileage))
    if (i < (count_names - 1)):
        file.write('\n')

file.close()