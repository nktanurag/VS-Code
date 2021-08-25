import pygame
import random
import math
from pygame import mixer 

#initialize the pygame 
pygame.init()

#creating the SCreen
screen=pygame.display.set_mode((800,600))


#background image
background=pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\background.png')
mixer.music.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\backgroundMusic1.wav')
mixer.music.play(-1)


#caption and icon
pygame.display.set_caption("Space Invader")
icon=pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\ufo.png')
pygame.display.set_icon(icon)

#score
score=0
font=pygame.font.Font('freesansbold.ttf',32)
textX=10
textY=10

def showScore(x,y):
    score_value=font.render("Score:" +str(score),True,(255,255,255))
    screen.blit(score_value,(x,y))


#gameovertext
isGameOver=False
over_font=pygame.font.Font('freesansbold.ttf',64)

def showGameOver():
    over_text=over_font.render("Game Over",True,(255,255,255))
    screen.blit(over_text,(200,250))

#player
playerImg=pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\player.png')
playerX=370.0
playerY=480.0
playerX_change=0.0
playerY_change=0.0


#enemy
enemyImg=[]
enemyX=[]
enemyY=[]
enemyX_change=[]
enemyY_change=[]
enemyCount=6

for i in range(enemyCount):
    enemyImg.append(pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\enemy.png'))
    enemyX.append(random.randint(0,735))
    enemyY.append(random.randint(10,150))
    enemyX_change.append(6)
    enemyY_change.append(15)


#bullet

#ready->bullet cant be seen ,fired->bullet moving
bulletImg=pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\bullet.png')
bulletX=playerX
bulletY=playerY
bulletX_change=0
bulletY_change=-10
bullet_state="ready"   


def player(x,y):
    screen.blit(playerImg,(x,y))                   #to draw


def enemy(x,y,i):
    screen.blit(enemyImg[i],(x,y))

def fireBullet(x,y):
    global bullet_state
    bullet_state="fired"
    screen.blit(bulletImg,(x+16,y+10))

def isCollision(enemyX,enemyY,bulletX,bulletY):
    dist=math.sqrt(math.pow(enemyX-bulletX,2)+math.pow(enemyY-bulletY,2))
    if dist<27.0:
        return True
    else:
        return False

def showCollisionBlast(x,y):
    bulletImg=pygame.image.load(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\blast.png')
    screen.blit(bulletImg,(x,y))



#game loop
running =True
while running:

    #rgb
    screen.fill((0,0,0))
    #background image
    screen.blit(background,(0,0))
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            running=False

        #keystroke press left,right,up,down
        if event.type==pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerX_change=-5
            if event.key == pygame.K_RIGHT:
                playerX_change=5
            if event.key == pygame.K_UP:
                playerY_change=-5
            if event.key == pygame.K_DOWN:
                playerY_change=5
            if event.key == pygame.K_SPACE:
                if bullet_state=="ready":
                    bulletSound=mixer.Sound(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\laser.wav')
                    bulletSound.play()
                    bulletX=playerX
                    bulletY=playerY
                    fireBullet(bulletX,bulletY)
        
        if event.type==pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerX_change=0.0
            if event.key == pygame.K_UP or event.key == pygame.K_DOWN:
                playerY_change=0.0


    #players movement
    playerX+=playerX_change
    playerY+=playerY_change

    #creating boundary for players
    if playerX>=736:     #800-64
        playerX=736
    if playerX<=0:
        playerX=0
    if playerY>=534:
        playerY=534
    if playerY<0:
        playerY=0
    #boundary created for players

    #enemy movement
    
    for i in range(enemyCount) :
        if isGameOver==True:
            break
        #GameOver
        #if any enemy missed to be shot or collision
        for j in range(enemyCount):
            d=math.sqrt(math.pow(enemyX[j]-playerX,2)+math.pow(enemyY[j]-playerY,2))
            if d<27.0 or enemyY[j]>534 :
                isGameOver=True
                break
        if isGameOver==True:
            break

    

        enemyX[i]+=enemyX_change[i]
        #creating boundary for enemy
        if  enemyX[i]>=736:     #800-64
            enemyX_change[i]=0-6
            enemyY[i]+=enemyY_change[i]
        elif enemyX[i]<=0:
            enemyX_change[i]=6
            enemyY[i]+=enemyY_change[i]
        elif enemyY[i]<=0:
            isGameOver=True
        
        #collision
        collision=isCollision(enemyX[i],enemyY[i],bulletX,bulletY)
        if collision:
            collisionSound=mixer.Sound(r'C:\Users\HP\OneDrive\Documents\CODE EDITOR\SpaceInvader\collision.wav')
            collisionSound.play()
            showCollisionBlast(enemyX[i],enemyY[i])
            bulletY=480
            bullet_state="ready"
            score+=1
            print(score)
            enemyX[i]=random.randint(0,735)
            enemyY[i]=random.randint(10,150)
            
        enemy(enemyX[i],enemyY[i],i)
    if isGameOver:
        showGameOver()
            


    
    #boundary created for enemy


    #bullet movement
    if bulletY<=0:
        bulletY=480
        bullet_state="ready"
    if bullet_state is "fired":
        fireBullet(bulletX,bulletY)
        bulletY+=bulletY_change

    

    player(playerX,playerY)
    showScore(textX,textY)

    pygame.display.update()
    


