
#include "opencv2/imgproc.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/opencv.hpp"

#include <stdio.h>  
/* A Simple Camera Capture Framework */
int main() 
{
   CvCapture* capture = cvCaptureFromCAM( CV_CAP_XIAPI );
   if ( !capture ) {
     fprintf( stderr, "ERROR: capture is NULL \n" );
     getchar();
     return -1;
   }
   /* Create a window in which the captured images will be presented */
   cvNamedWindow( "mywindow", CV_WINDOW_AUTOSIZE );
   /* Show the image captured from the camera in the window and repeat */
   long int frame_cnt = 0;
   while ( 1 ) {
     IplImage* frame = cvQueryFrame( capture );
     if ( !frame ) {
       fprintf( stderr, "ERROR: frame is null...\n" );
       getchar();
       break;
     }
     frame_cnt++;
     cvShowImage( "mywindow", frame );
     if ( (cvWaitKey(10) & 255) == 27 ) break;
   }

   cvReleaseCapture( &capture );
   cvDestroyWindow( "mywindow" );
   printf("frame count = %ld", frame_cnt);
   return 0;
}
