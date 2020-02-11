import serial
import pygame

arduinoData = serial.Serial('/dev/ttyACM0')
# pygame.mixer.pre_init(220500, 16, 2, 4096)
pygame.mixer.init()
started1 = False
started2 = False

while True:
    cc=str(arduinoData.readline())
    print(cc[2:][:-5])
    print("Stop1" in cc[2:][:-5])
    print(cc)

    if("Start1" in cc[2:][:-5] and not started1):
        pygame.mixer.music.load("do_not_worry.mp3")
        started1= True
        pygame.mixer.music.play()

    if("Stop1" in cc[2:][:-5] and started1):
        started1= False
        pygame.mixer.music.stop()

    if("Start2" in cc[2:][:-5] and not started2):
        pygame.mixer.music.load("shake_it_off.mp3")
        started2= True
        pygame.mixer.music.play()

    if("Stop2" in cc[2:][:-5] and started2):
        started2= False
        pygame.mixer.music.stop()
