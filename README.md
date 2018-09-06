ofxCubeMap
==========

Addon for working with Cube Maps in openFrameworks


Usage:
----------

To load some images into a cubemap:

		myCubeMap.load( "Cubemaps/SummerScene/cubescene_rt.jpg",
						      "Cubemaps/SummerScene/cubescene_lf.jpg",						 
						      "Cubemaps/SummerScene/cubescene_up.jpg",
						      "Cubemaps/SummerScene/cubescene_dn.jpg",
						      "Cubemaps/SummerScene/cubescene_fr.jpg",
						      "Cubemaps/SummerScene/cubescene_bk.jpg" );


Then to draw it:

		myCubeMap.bind();
			myCubeMap.drawSkybox( ofVec3f(0), 800 );
		myCubeMap.unbind();

It can also be drawn using the supplied shader doing something like:

	myCubeMap.bind();

		cubeMapShader.begin();
		cubeMapShader.setUniform1i("EnvMap", 0);

			myCubeMap.drawSkybox( ofVec3f(0), 800 );

		cubeMapShader.end();

	myCubeMap.unbind();


To initialise an FBO based cubemap that you can draw into:

	myFboCubeMap.initEmptyTextures( 512 );


To draw into it in 2D, this will clear each face to black and draw a line from one corner to the other

	for( int i = 0; i < 6; i++ )
	{
		myFboCubeMap.beginDrawingInto2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i );

			ofClear(0,0,0);

			ofLine(0,0, myFboCubeMap.getWidth(), myFboCubeMap.getHeight() );
			ofLine(myFboCubeMap.getWidth(), 0, 0, myFboCubeMap.getHeight() );

		myFboCubeMap.endDrawingInto2D();
	}



If you want to draw your 3D scene into it, you can place it in the scene:

	myFboCubeMap.setPosition( 0.0f, 40.0f, 0.0f );

And then you can draw the 3D scene into it like so:

	for( int i = 0; i < 6; i++ )
	{
		myFboCubeMap.beginDrawingInto3D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + i );

			ofClear(0,0,0);
			drawScene();

		myFboCubeMap.endDrawingInto3D();
	}

If you use a compiler which supports C++11, you can define the ```OFXCUBEMAP_LAMBDAS``` preprocessor flag to enable lambda features by adding the following line to your config.make;
```
PROJECT_DEFINES = OFXCUBEMAP_LAMBDAS
```

Then the above example to draw your 3D scene into your CubeMap can also be written like this;

```c++
myFboCubeMap.drawInto3D([](){
	// this part is executed 6 times;
	// once for each face of the cubemap
	ofClear(0,0,0);
	drawScene();
});
```

Examples coming when I get a chance.
