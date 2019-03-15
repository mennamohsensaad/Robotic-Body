# Assignment 2 report.

## Prepared by 

#  NAME :- Menna Mohsen Saad


#  sec:- 2


#  B.N :- 29




## implementations

###  1-for Full Body 
  it consists of head,trunk,2arms,2leges,2foots and fingers.Each of all just a cube so,first i draw the trunk and head above it  and localized them 0
  then i put each one of them in a seperated matrix started with push and ends with pop.

for example :
```
	// draw trunck
	glPushMatrix();
	glTranslatef(0, 3, 0.0);
	glColor3f(0.5, 0.25, 0.25);
	glScalef(3, 6, 1);
	glutWireCube(1.0);
	glPopMatrix();
```

Then i draw the left and right arm each one consists of shoulder ,elbow and four fingers 
each part in a seperated matrix startes with push and ends with pop.
###### Note That
shoulder will do 2 rotation:  first rotate about x-axis (shoulder in code ) ,second rotate about its axis or y-axis  (shoulder2 in code ) 
for example :
```
    //shoulder
    glPushMatrix();
	glTranslatef(-2, 6, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulder2, 0.0, 1.0, 0.0);
	glTranslatef(0.0, -1, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2, 1.0);
	glutWireCube(1);
	glPopMatrix();
	//elbow
	glTranslatef(0, -1, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(0, -1, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
	 // finger 1
	glPushMatrix();
	glTranslatef(-0.3, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1, 0.0,0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//and so on for other fingers 
```
And i draw the left and right leg each one consists of hip ,knee and foot 
each part in a seperated matrix startes with push and ends with pop.

###### Note That
hip will do 2 movements: first right and left (hip in code ) ,second forward and backward (hip2 in code ) 
for example :
```
    //righthip
	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)rhip, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)rhip2, 0.0, 0.0, 0.1);
	glTranslatef(0.0, -1.5, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//rightknee
	glTranslatef(0, -1.5, 0.0);
	glRotatef((GLfloat)rknee, 0.1, 0.0, 0.0);
	glTranslatef(0, -1.5, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
    //rightfoot
	glPushMatrix();
	glTranslatef(0.1, -1.3, 0.1);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1.3, 1, 2.5);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
```

### 2-for camera movements :
####       1- Move forward
center and up vector is fixed where eye vector "only" is changed
so distance become  center-eye
for example:
```
direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];

	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
```

####         2- Move backward
same as moving forward but with increasing in distance
for example: there is only difference in eye & center equation
```
        eye[0] -= direction[0] * speed;
	eye[1] -= direction[1] * speed;
	eye[2] -= direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;

```
####          3-left and right
we rotate around up vector by 'theta'  for left & '-theta' for right, and we rotate by eye
for example:
```
void Left()
{
	rotatePoint(up, 0.05, eye);
}

void Right()
{
	rotatePoint(up, -0.05, eye);
}

```
####         4-up and down 

center vector is fixed where eye vector is changed 
so up vector is changed also to be perpendicular on the direction between center and eye 

for examle:
```
void Up()
{
	double V[] = { 0,0,0 };
	crossProduct(eye, up, V);
	normalize(V);
	rotatePoint(V, 0.05, eye);
	rotatePoint(V, 0.05,up);

}

void Down()
{
	double V[] = { 0,0,0 };
	crossProduct(eye, up, V);
	normalize(V);
	rotatePoint(V, -0.05, eye);
	rotatePoint(V, -0.05, up);

}
```

# problem faced me
time not enough for me with other taskes which  i have  
