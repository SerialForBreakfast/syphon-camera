//
//  SyphonSender.h
//  SyphonNetCamera
//
//  Created by Normen Hansen on 17.05.12.
//  Copyright (c) 2012 Normen Hansen. Released under New BSD license.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>
#import <OpenGL/glext.h>
#import <Syphon/Syphon.h>
#import "turbojpeg.h"
#import "NetCamClient.h"

@interface SyphonSender : NSObject<NetCamClientDelegate>{
    NSOpenGLContext *glContext;
    SyphonServer *server;
    NetCamClient *client;
    
    GLuint framebuffer, renderbuffer;
    GLuint texture;
    void *imageData;
    NSInteger curWidth;
    NSInteger curHeight;
    
    NSThread *readThread;
    
    tjhandle jpeg;

    BOOL finished;
}

- (id)initWithData:(NSDictionary *)dict;
- (NSDictionary *)getData;

- (void) netCamClient:(NetCamClient*) client didReceiveImage:(NSData*) imagedata;
- (void) netCamClient:(NetCamClient*) client didReceiveError:(NSError*) error;
- (void) cleanup;

@property (nonatomic, assign) NSString *url;
@property (nonatomic, assign) NSString *user;
@property (nonatomic, assign) NSString *password;
@property (nonatomic, assign) NSString *name;
@property (nonatomic) BOOL enabled;

@end
