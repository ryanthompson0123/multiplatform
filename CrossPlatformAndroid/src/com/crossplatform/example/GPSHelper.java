// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
package com.crossplatform.example;

import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;

/**
 *
 * @author Ryan
 */
public class GPSHelper {
	private static GPSHelper sharedInstance;
	
	private Context context;
	private XPController controller;
	
	private static final LocationListener listener = new LocationListener() {
		@Override
		public void onLocationChanged(Location location) {
			GPSHelper helper = GPSHelper.getInstance();
			XPLocation xLoc = new XPLocation();
			xLoc.setLatitude(location.getLatitude());
			xLoc.setLongitude(location.getLongitude());
			xLoc.setAltitude(location.getAltitude());
			xLoc.setSpeed(location.getSpeed());
			xLoc.setHeading(location.getBearing());
			
			helper.controller.locationUpdated(xLoc);
		}

		@Override
		public void onProviderDisabled(String arg0) {			
		}

		@Override
		public void onProviderEnabled(String arg0) {			
		}

		@Override
		public void onStatusChanged(String arg0, int arg1, Bundle arg2) {
		}
	};
	
	public static GPSHelper getInstance() {
		if (sharedInstance == null) {
			sharedInstance = new GPSHelper();
		}
		
		return sharedInstance;
	}
	
    private GPSHelper() {}
    
    public void setContext(Context context) {
    	this.context = context;
    }
    
    public void setController(XPController controller) {
    	this.controller = controller;
    }
    
    public static void startUpdating() {
        LocationManager manager = (LocationManager)sharedInstance.context.getSystemService(Context.LOCATION_SERVICE);
        
        manager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 1000, 10, listener);
    }
    
    public static void stopUpdating() {
    	LocationManager manager = (LocationManager)sharedInstance.context.getSystemService(Context.LOCATION_SERVICE);
    	
    	manager.removeUpdates(listener);
    }
    
    
}
