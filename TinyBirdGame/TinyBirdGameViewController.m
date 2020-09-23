//
//  TinyBirdGameViewController.m
//  NewTest
//
//  Created by 兖志飞 on 2020/7/14.
//  Copyright © 2020 yanzf. All rights reserved.
//

#import "TinyBirdGameViewController.h"
#import "MySKScene.h"
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <SpriteKit/SpriteKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Vision/Vision.h>

@interface TinyBirdGameViewController ()<SKSceneDelegate,AVCaptureVideoDataOutputSampleBufferDelegate>
@property (strong,strong) SKView * gameView;
@property (nonatomic,strong) AVCaptureSession *session;
@property (nonatomic,strong) UIImageView *cameraView;
@property (strong, nonatomic) AVCaptureVideoPreviewLayer * previewLayer;
@property (nonatomic,strong) dispatch_queue_t sample;
@property (nonatomic,strong) dispatch_queue_t faceQueue;
@property (nonatomic,copy) NSArray *currentMetadata;
@property (nonatomic,copy) MySKScene *sc;
@property (nonatomic,assign) BOOL isCheck;
@end

@implementation TinyBirdGameViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self addVision];
    [self addSKView];
}
- (void)addSKView{
    self.gameView = [[SKView alloc]initWithFrame:self.view.frame];
    [self.view addSubview:self.gameView];
    self.gameView.showsFPS = YES;
    self.gameView.backgroundColor = [UIColor clearColor];
    _isCheck = NO;
    _sc = [[MySKScene alloc] initWithSize:self.gameView.bounds.size];
    _sc.scaleMode = SKSceneScaleModeAspectFill;
    _sc.backgroundColor = [UIColor clearColor];
    __weak typeof(self) weakSelf = self;
    _sc.block = ^(NSString * title){
        if([title isEqualToString:@"1"]){
            [weakSelf showSheetWithTitle:[NSString stringWithFormat:@"游戏结束得分%ld是否继续",(long)weakSelf.sc.score] number:@"1"];
        }else if([title isEqualToString:@"2"]){
            [weakSelf showSheetWithTitle:[NSString stringWithFormat:@"游戏已经暂定,是否继续"] number:@"2"];
        }
    };
    [self.gameView presentScene:_sc];
}
#pragma vision
- (void)addVision{
    _currentMetadata = [NSMutableArray arrayWithCapacity:0];
    _sample = dispatch_queue_create("sample", NULL);
    _faceQueue = dispatch_queue_create("face", NULL);
    AVCaptureVideoDataOutput *output = [[AVCaptureVideoDataOutput alloc] init];
    NSArray *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    AVCaptureDevice *deviceF;
    for (AVCaptureDevice *device in devices )
    {
        if ( device.position == AVCaptureDevicePositionFront )
        {
            deviceF = device;
            break;
        }
    }
    AVCaptureDeviceInput*input = [[AVCaptureDeviceInput alloc] initWithDevice:deviceF error:nil];
    [output setSampleBufferDelegate:self queue:_sample];
    AVCaptureMetadataOutput *metaout = [[AVCaptureMetadataOutput alloc] init];
    [metaout setMetadataObjectsDelegate:self queue:_faceQueue];
    self.session = [[AVCaptureSession alloc] init];
    [self.session beginConfiguration];
    if ([self.session canAddInput:input]) {
        [self.session addInput:input];
    }
    if ([self.session canSetSessionPreset:AVCaptureSessionPreset640x480]) {
        [self.session setSessionPreset:AVCaptureSessionPreset640x480];
    }
    if ([self.session canAddOutput:output]) {
        [self.session addOutput:output];
    }
    if ([self.session canAddOutput:metaout]) {
        [self.session addOutput:metaout];
    }
    [self.session commitConfiguration];
    NSString     *key           = (NSString *)kCVPixelBufferPixelFormatTypeKey;
    NSNumber     *value         = [NSNumber numberWithUnsignedInt:kCVPixelFormatType_32BGRA];
    NSDictionary *videoSettings = [NSDictionary dictionaryWithObject:value forKey:key];
    [output setVideoSettings:videoSettings];
    [metaout setMetadataObjectTypes:@[AVMetadataObjectTypeFace]];
    for (AVCaptureVideoDataOutput* output in _session.outputs) {
        for (AVCaptureConnection * av in output.connections) {
            //判断是否是前置摄像头状态
            if (av.supportsVideoMirroring) {
                //镜像设置
                av.videoOrientation = AVCaptureVideoOrientationPortrait;
                av.videoMirrored = YES;
            }
        }
    }
    [self.session startRunning];
    [self.view.layer addSublayer:self.previewLayer];
}
- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    if(_isCheck){
        _isCheck = !_isCheck;
        return;
    }
    if(@available(iOS 11.0, *)) {
        CVPixelBufferRef cvpixeBufferRef = CMSampleBufferGetImageBuffer(sampleBuffer);
        VNImageRequestHandler *handler = [[VNImageRequestHandler alloc] initWithCVPixelBuffer:cvpixeBufferRef options:@{}];
        VNImageBasedRequest *request = [[VNImageBasedRequest alloc] init];
        request = [[VNDetectFaceRectanglesRequest alloc] initWithCompletionHandler:^(VNRequest * _Nonnull request, NSError * _Nullable error) {
            NSArray *vnobservations = request.results;
            dispatch_async(dispatch_get_main_queue(), ^{
                for (VNFaceObservation *faceObservation in vnobservations) {
                    //boundingBox
                    CGRect transFrame = [self convertRect:faceObservation.boundingBox imageSize:self.view.frame.size];
                    CGFloat tt = transFrame.size.height/2.0 + transFrame.origin.y;
                    [self.sc bridSetLocationL:tt];
                    return;
                }
            });
        }];
        [handler performRequests:@[request] error:nil];
    }
}

- (void)captureOutput:(AVCaptureOutput *)output didOutputMetadataObjects:(NSArray<__kindof AVMetadataObject *> *)metadataObjects fromConnection:(AVCaptureConnection *)connection
{
    self.currentMetadata = metadataObjects;
}

-(AVCaptureVideoPreviewLayer *)previewLayer{
    if (!_previewLayer) {
        _previewLayer = [AVCaptureVideoPreviewLayer layerWithSession:self.session];
        self.previewLayer.frame = self.view.bounds;
        _previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    }
    return _previewLayer;
}
//将设备坐标空间转换为视图空间对象集合
- (NSArray *)transformedFacesFromFaces:(NSArray *)faces {
    NSMutableArray *transformedFaces = [NSMutableArray array];
    for (AVMetadataObject *face in faces) {
        AVMetadataObject *transformedFace =                                 // 3
        [self.previewLayer transformedMetadataObjectForMetadataObject:face];
        [transformedFaces addObject:transformedFace];
    }
    return transformedFaces;
}

- (CGRect)convertRect:(CGRect)boundingBox imageSize:(CGSize)imageSize{
    CGFloat w = boundingBox.size.width * imageSize.width;
    CGFloat h = boundingBox.size.height * imageSize.height;
    CGFloat x = boundingBox.origin.x * imageSize.width;
    CGFloat y = imageSize.height * (1 - boundingBox.origin.y - boundingBox.size.height);
    return CGRectMake(x, y, w, h);
}

- (void)showSheetWithTitle:(NSString *)title number:(NSString *)number{
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@""
                                                                   message:title
                                                            preferredStyle:UIAlertControllerStyleAlert];
    if([number isEqualToString:@"1"]){
        UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"退出" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * action) {
            if(self.block !=nil){
                self.block([NSString stringWithFormat:@"%ld",(long)self.sc.score]);
            }
            [self dismissViewControllerAnimated:YES completion:^{
                
            }];
        }];
        [alert addAction:cancelAction];
        
        UIAlertAction* cancelAction1 = [UIAlertAction actionWithTitle:@"再来一局" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {
            [self.sc startGame];
        }];
        [alert addAction:cancelAction1];
    }
    if([number isEqualToString:@"2"]){
        UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"退出" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * action) {
            if(self.block !=nil){
                self.block([NSString stringWithFormat:@"%ld",(long)self.sc.score]);
            }
            [self dismissViewControllerAnimated:YES completion:^{
                
            }];
        }];
        [alert addAction:cancelAction];
        
        UIAlertAction* cancelAction1 = [UIAlertAction actionWithTitle:@"继续" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {
            self.sc.paused = NO;
        }];
        [alert addAction:cancelAction1];
    }
    
    [self presentViewController:alert animated:YES completion:nil];
}
@end
