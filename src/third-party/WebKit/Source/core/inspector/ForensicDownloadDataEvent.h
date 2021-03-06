
/*
 * Copyright (C) 2015 University of Georgia. All rights reserved.
 *
 * This file is subject to the terms and conditions defined at
 * https://github.com/perdisci/WebCapsule/blob/master/LICENSE.txt
 *
 */


#ifndef ForensicDownloadDataEvent_h
#define ForensicDownloadDataEvent_h

#include "core/inspector/ForensicEvent.h"

namespace WebCore {
class ForensicEventVisitor;

class ForensicDownloadDataEvent FINAL : public ForensicEvent {
public:
	static PassRefPtr<ForensicDownloadDataEvent> create(int, int, const double);
	static PassRefPtr<ForensicDownloadDataEvent> create(PassRefPtr<JSONObject> obj);

	virtual ~ForensicDownloadDataEvent();

	int dataLength();
	int encodedDataLength();

	virtual void accept(ForensicEventVisitor& visitor) OVERRIDE;
	virtual size_t size();

	virtual PassRefPtr<JSONObject> serialize() OVERRIDE;
	virtual void deserialize(PassRefPtr<JSONObject> json) OVERRIDE;

private:
	ForensicDownloadDataEvent(PassRefPtr<JSONObject> obj);
	ForensicDownloadDataEvent(int, int, const double);

	int m_dataLength;
	int m_encodedDataLength;

};

} /* namespace WebCore */
#endif /* ForensicDownloadDataEvent_h */
