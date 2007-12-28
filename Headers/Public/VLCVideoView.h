/*****************************************************************************
 * VLCVideoView.h: VLC.framework VLCVideoView header
 *****************************************************************************
 * Copyright (C) 2007 Pierre d'Herbemont
 * Copyright (C) 2007 the VideoLAN team
 * $Id$
 *
 * Authors: Pierre d'Herbemont <pdherbemont # videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
@class CALayer;

/* Notifications */
extern NSString * VLCVideoViewEnteredFullScreen;
extern NSString * VLCVideoViewLeftFullScreen;

@protocol VLCVideoViewDelegate
// Notifications defined in VLCVideoView.h
- (void)videoEnteredFullscreen:(NSNotification *)aNotification;
- (void)videoLeftFullscreen:(NSNotification *)aNotification;
@end

@interface VLCVideoView : NSView
{
    id delegate;
    NSColor * backColor;
    BOOL stretchesVideo;
    BOOL fullscreen;
    id layoutManager;
    // TODO: Allow for view to report transparency to do some cool effects
    // with the video?
}

@property (readonly, assign) BOOL fullscreen;
@property BOOL fillScreen;

- (void)setDelegate:(id)value;
- (id)delegate;

- (void)setBackColor:(NSColor *)value;
- (NSColor *)backColor;

- (void)enterFullscreen;
- (void)leaveFullscreen;

//- (void)setOnTop: (BOOL)ontop; /* Do we really want that in protocol? */

// The media controls that were here previously should be moved elsewhere.  This
// View is just that, a view not a controller. -- Moved to VLCMediaPlayer
@end
