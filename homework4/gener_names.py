import random
import datetime
lastname =['Abramov', 'Avdeev', 'Agafonov', 'Aleksandrov', 'Alekseev', 'Andreev', 'Antonov','Baranov', 'Belov', 'Beloysov', 'Belyaev', 'Belyakov',
           'Bespalov', 'Blinov', 'Blohin', 'Bobrov', 'Bogdanov','Borisov', 'Bragin', 'Byrov', 'Veselov', 'Vinogradov', 'Vishnyakov', 'Vladimirov',
           'Vlasov', 'Volkov', 'Voronov', 'Voroncov', 'Gavrilov', 'Galkin']
initials = ['A', 'B', 'V', 'G', 'D', 'E', 'Z', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'F', 'U']
cars = ['Audi', 'BMW', 'Ford', 'Honda', 'Hyundai', 'Kia', 'Lada', 'Mazda', 'Mitsubishi', 'Nissan', 'Renault', 'Skoda', 'Toyota', 'Volkswagen',
        'Acura', 'Daihatsu', 'Datsun', 'Honda', 'Infiniti', 'Isuzu', 'Lexus', 'Mazda', 'Mitsubishi', 'Nissan', 'Scion', 'Subaru', 'Suzuki',
        'Toyota', 'Buick', 'Cadillac', 'Chevrolet', 'Chrysler', 'Dodge', 'Ford', 'GMC', 'Hummer', 'Jeep', 'Lincoln', 'Mercury', 'Oldsmobile',
        'Pontiac', 'Tesla', 'Lada', 'ГАЗ', 'Москвич', 'ТагАЗ', 'УАЗ', 'Audi', 'BMW', 'Opel', 'Porsche', 'Volkswagen', 'Daewoo', 'Genesis', 'Hyundai',
        'Kia', 'SsangYong', 'Bentley', 'Bugatti', 'Citroen', 'DS', 'Ferrari', 'Fiat', 'Jaguar', 'Lamborghini', 'Lancia', 'Maserati', 'Maybach', 'Mini',
        'Peugeot', 'Ravon','Renault', 'Rover', 'Saab', 'SEAT', 'Skoda', 'Smart', 'Volvo', 'ZAZ', 'Brilliance', 'BYD', 'Changan', 'Chery', 'DongFeng',
        'FAW', 'Foton', 'GAC', 'Geely', 'Haima', 'Haval', 'JAC', 'Lifan', 'Luxgen', 'Zotye']

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
                ' ' + str(bus_number) + ' ' + 'M'+str(bus_number) + ' ' + random.choice(cars) + ' ' + str(year) + ' ' + str(mileage))
    if (i < (count_names - 1)):
        file.write('\n')

file.close()
