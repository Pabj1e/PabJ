<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dynamic Calendar Schedule</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            padding: 20px;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            background: rgba(255, 255, 255, 0.95);
            backdrop-filter: blur(10px);
            border-radius: 20px;
            box-shadow: 0 20px 40px rgba(0, 0, 0, 0.1);
            overflow: hidden;
        }

        .header {
            background: linear-gradient(135deg, #4facfe 0%, #00f2fe 100%);
            padding: 30px;
            text-align: center;
            color: white;
        }

        .header h1 {
            font-size: 2.5rem;
            margin-bottom: 10px;
            text-shadow: 0 2px 4px rgba(0, 0, 0, 0.3);
        }

        .controls {
            display: flex;
            justify-content: center;
            align-items: center;
            gap: 20px;
            margin-top: 20px;
        }

        .nav-btn {
            background: rgba(255, 255, 255, 0.2);
            border: 2px solid rgba(255, 255, 255, 0.3);
            color: white;
            padding: 10px 20px;
            border-radius: 10px;
            cursor: pointer;
            transition: all 0.3s ease;
            font-size: 1rem;
        }

        .nav-btn:hover {
            background: rgba(255, 255, 255, 0.3);
            transform: translateY(-2px);
        }

        .month-year {
            font-size: 1.5rem;
            font-weight: bold;
            min-width: 200px;
        }

        .calendar-container {
            padding: 30px;
        }

        .calendar {
            display: grid;
            grid-template-columns: repeat(7, 1fr);
            gap: 1px;
            background: #e0e0e0;
            border-radius: 10px;
            overflow: hidden;
            margin-bottom: 30px;
        }

        .day-header {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 15px;
            text-align: center;
            font-weight: bold;
            font-size: 0.9rem;
        }

        .day {
            background: white;
            min-height: 120px;
            padding: 10px;
            cursor: pointer;
            transition: all 0.3s ease;
            position: relative;
            display: flex;
            flex-direction: column;
        }

        .day:hover {
            background: #f0f8ff;
            transform: scale(1.02);
        }

        .day.other-month {
            background: #f5f5f5;
            color: #ccc;
        }

        .day.today {
            background: linear-gradient(135deg, #ffeaa7 0%, #fab1a0 100%);
            box-shadow: 0 4px 15px rgba(255, 234, 167, 0.6);
        }

        .day.selected {
            background: linear-gradient(135deg, #a8edea 0%, #fed6e3 100%);
            box-shadow: 0 4px 15px rgba(168, 237, 234, 0.6);
        }

        .day-number {
            font-weight: bold;
            margin-bottom: 5px;
            color: #333;
        }

        .event {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 4px 8px;
            border-radius: 15px;
            font-size: 0.8rem;
            margin-bottom: 3px;
            cursor: pointer;
            transition: all 0.2s ease;
            overflow: hidden;
            text-overflow: ellipsis;
            white-space: nowrap;
        }

        .event:hover {
            transform: translateY(-1px);
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.2);
        }

        .event-form {
            background: white;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            z-index: 1000;
            width: 90%;
            max-width: 500px;
            display: none;
        }

        .event-form.show {
            display: block;
            animation: slideIn 0.3s ease;
        }

        @keyframes slideIn {
            from {
                opacity: 0;
                transform: translate(-50%, -60%);
            }
            to {
                opacity: 1;
                transform: translate(-50%, -50%);
            }
        }

        .overlay {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(0, 0, 0, 0.5);
            z-index: 999;
            display: none;
        }

        .overlay.show {
            display: block;
        }

        .form-group {
            margin-bottom: 20px;
        }

        .form-group label {
            display: block;
            margin-bottom: 8px;
            font-weight: bold;
            color: #333;
        }

        .form-group input, .form-group textarea {
            width: 100%;
            padding: 12px;
            border: 2px solid #e0e0e0;
            border-radius: 10px;
            font-size: 1rem;
            transition: border-color 0.3s ease;
        }

        .form-group input:focus, .form-group textarea:focus {
            outline: none;
            border-color: #667eea;
            box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);
        }

        .form-buttons {
            display: flex;
            gap: 15px;
            justify-content: flex-end;
        }

        .btn {
            padding: 12px 24px;
            border: none;
            border-radius: 10px;
            cursor: pointer;
            font-size: 1rem;
            transition: all 0.3s ease;
            font-weight: bold;
        }

        .btn-primary {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
        }

        .btn-primary:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
        }

        .btn-secondary {
            background: #f0f0f0;
            color: #666;
        }

        .btn-secondary:hover {
            background: #e0e0e0;
        }

        .btn-danger {
            background: linear-gradient(135deg, #fd79a8 0%, #fdcb6e 100%);
            color: white;
        }

        .btn-danger:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(253, 121, 168, 0.4);
        }

        .save-status {
            text-align: center;
            padding: 10px;
            margin-top: 20px;
            border-radius: 10px;
            background: linear-gradient(135deg, #00b894 0%, #00cec9 100%);
            color: white;
            font-weight: bold;
            opacity: 0;
            transition: opacity 0.3s ease;
        }

        .save-status.show {
            opacity: 1;
        }

        @media (max-width: 768px) {
            .calendar {
                font-size: 0.8rem;
            }
            
            .day {
                min-height: 100px;
                padding: 5px;
            }
            
            .header h1 {
                font-size: 2rem;
            }
            
            .controls {
                flex-direction: column;
                gap: 10px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>📅 Dynamic Calendar Schedule</h1>
            <div class="controls">
                <button class="nav-btn" id="prevMonth">‹ Previous</button>
                <div class="month-year" id="monthYear"></div>
                <button class="nav-btn" id="nextMonth">Next ›</button>
            </div>
        </div>

        <div class="calendar-container">
            <div class="calendar" id="calendar"></div>
            <div class="save-status" id="saveStatus">Changes saved automatically!</div>
        </div>
    </div>

    <div class="overlay" id="overlay"></div>
    <div class="event-form" id="eventForm">
        <h3 id="formTitle">Add New Event</h3>
        <form id="eventFormElement">
            <div class="form-group">
                <label for="eventTitle">Event Title *</label>
                <input type="text" id="eventTitle" required>
            </div>
            <div class="form-group">
                <label for="eventTime">Time</label>
                <input type="time" id="eventTime">
            </div>
            <div class="form-group">
                <label for="eventDescription">Description</label>
                <textarea id="eventDescription" rows="3"></textarea>
            </div>
            <div class="form-buttons">
                <button type="button" class="btn btn-secondary" id="cancelBtn">Cancel</button>
                <button type="button" class="btn btn-danger" id="deleteBtn" style="display: none;">Delete</button>
                <button type="submit" class="btn btn-primary" id="saveBtn">Save Event</button>
            </div>
        </form>
    </div>

    <script>
        class CalendarSchedule {
            constructor() {
                this.currentDate = new Date();
                this.selectedDate = null;
                this.events = {}; // Store events in memory
                this.editingEvent = null;
                
                this.initializeElements();
                this.bindEvents();
                this.render();
                this.loadEvents();
            }

            initializeElements() {
                this.calendarEl = document.getElementById('calendar');
                this.monthYearEl = document.getElementById('monthYear');
                this.prevBtn = document.getElementById('prevMonth');
                this.nextBtn = document.getElementById('nextMonth');
                this.eventForm = document.getElementById('eventForm');
                this.overlay = document.getElementById('overlay');
                this.eventFormElement = document.getElementById('eventFormElement');
                this.formTitle = document.getElementById('formTitle');
                this.saveStatus = document.getElementById('saveStatus');
            }

            bindEvents() {
                this.prevBtn.addEventListener('click', () => this.previousMonth());
                this.nextBtn.addEventListener('click', () => this.nextMonth());
                this.overlay.addEventListener('click', () => this.closeEventForm());
                document.getElementById('cancelBtn').addEventListener('click', () => this.closeEventForm());
                document.getElementById('deleteBtn').addEventListener('click', () => this.deleteEvent());
                this.eventFormElement.addEventListener('submit', (e) => this.saveEvent(e));
            }

            previousMonth() {
                this.currentDate.setMonth(this.currentDate.getMonth() - 1);
                this.render();
            }

            nextMonth() {
                this.currentDate.setMonth(this.currentDate.getMonth() + 1);
                this.render();
            }

            render() {
                this.renderHeader();
                this.renderCalendar();
            }

            renderHeader() {
                const options = { year: 'numeric', month: 'long' };
                this.monthYearEl.textContent = this.currentDate.toLocaleDateString('en-US', options);
            }

            renderCalendar() {
                const year = this.currentDate.getFullYear();
                const month = this.currentDate.getMonth();
                
                // Clear calendar
                this.calendarEl.innerHTML = '';
                
                // Add day headers
                const dayHeaders = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];
                dayHeaders.forEach(day => {
                    const dayEl = document.createElement('div');
                    dayEl.className = 'day-header';
                    dayEl.textContent = day;
                    this.calendarEl.appendChild(dayEl);
                });

                // Get first day of month and number of days
                const firstDay = new Date(year, month, 1).getDay();
                const daysInMonth = new Date(year, month + 1, 0).getDate();
                const daysInPrevMonth = new Date(year, month, 0).getDate();
                
                const today = new Date();
                
                // Add previous month's trailing days
                for (let i = firstDay - 1; i >= 0; i--) {
                    const dayEl = this.createDayElement(
                        daysInPrevMonth - i, 
                        month - 1, 
                        year, 
                        'other-month'
                    );
                    this.calendarEl.appendChild(dayEl);
                }
                
                // Add current month days
                for (let day = 1; day <= daysInMonth; day++) {
                    let classes = '';
                    const currentDateStr = this.formatDate(new Date(year, month, day));
                    
                    // Check if today
                    if (year === today.getFullYear() && 
                        month === today.getMonth() && 
                        day === today.getDate()) {
                        classes += ' today';
                    }
                    
                    // Check if selected
                    if (this.selectedDate && this.selectedDate === currentDateStr) {
                        classes += ' selected';
                    }
                    
                    const dayEl = this.createDayElement(day, month, year, classes);
                    this.calendarEl.appendChild(dayEl);
                }
                
                // Add next month's leading days
                const totalCells = this.calendarEl.children.length - 7; // Subtract day headers
                const remainingCells = 42 - totalCells; // 6 weeks * 7 days
                
                for (let day = 1; day <= remainingCells; day++) {
                    const dayEl = this.createDayElement(
                        day, 
                        month + 1, 
                        year, 
                        'other-month'
                    );
                    this.calendarEl.appendChild(dayEl);
                }
            }

            createDayElement(day, month, year, classes = '') {
                const dayEl = document.createElement('div');
                dayEl.className = `day ${classes}`;
                
                const dayNumber = document.createElement('div');
                dayNumber.className = 'day-number';
                dayNumber.textContent = day;
                dayEl.appendChild(dayNumber);
                
                // Add events for this day
                const dateStr = this.formatDate(new Date(year, month, day));
                if (this.events[dateStr]) {
                    this.events[dateStr].forEach(event => {
                        const eventEl = document.createElement('div');
                        eventEl.className = 'event';
                        eventEl.textContent = event.time ? `${event.time} - ${event.title}` : event.title;
                        eventEl.addEventListener('click', (e) => {
                            e.stopPropagation();
                            this.editEvent(dateStr, event);
                        });
                        dayEl.appendChild(eventEl);
                    });
                }
                
                // Add click handler for day
                dayEl.addEventListener('click', () => {
                    if (!classes.includes('other-month')) {
                        this.selectDate(dateStr);
                        this.openEventForm(dateStr);
                    }
                });
                
                return dayEl;
            }

            formatDate(date) {
                return date.toISOString().split('T')[0];
            }

            selectDate(dateStr) {
                this.selectedDate = dateStr;
                this.render();
            }

            openEventForm(dateStr) {
                this.selectedDate = dateStr;
                this.editingEvent = null;
                this.formTitle.textContent = `Add Event for ${new Date(dateStr).toLocaleDateString()}`;
                document.getElementById('eventTitle').value = '';
                document.getElementById('eventTime').value = '';
                document.getElementById('eventDescription').value = '';
                document.getElementById('deleteBtn').style.display = 'none';
                this.showForm();
            }

            editEvent(dateStr, event) {
                this.selectedDate = dateStr;
                this.editingEvent = event;
                this.formTitle.textContent = `Edit Event for ${new Date(dateStr).toLocaleDateString()}`;
                document.getElementById('eventTitle').value = event.title;
                document.getElementById('eventTime').value = event.time || '';
                document.getElementById('eventDescription').value = event.description || '';
                document.getElementById('deleteBtn').style.display = 'inline-block';
                this.showForm();
            }

            showForm() {
                this.eventForm.classList.add('show');
                this.overlay.classList.add('show');
                document.getElementById('eventTitle').focus();
            }

            closeEventForm() {
                this.eventForm.classList.remove('show');
                this.overlay.classList.remove('show');
                this.editingEvent = null;
            }

            saveEvent(e) {
                e.preventDefault();
                
                const title = document.getElementById('eventTitle').value.trim();
                const time = document.getElementById('eventTime').value;
                const description = document.getElementById('eventDescription').value.trim();
                
                if (!title) {
                    alert('Please enter an event title');
                    return;
                }
                
                const event = {
                    id: this.editingEvent ? this.editingEvent.id : Date.now(),
                    title,
                    time,
                    description
                };
                
                if (!this.events[this.selectedDate]) {
                    this.events[this.selectedDate] = [];
                }
                
                if (this.editingEvent) {
                    // Update existing event
                    const index = this.events[this.selectedDate].findIndex(e => e.id === this.editingEvent.id);
                    if (index !== -1) {
                        this.events[this.selectedDate][index] = event;
                    }
                } else {
                    // Add new event
                    this.events[this.selectedDate].push(event);
                }
                
                this.saveEvents();
                this.render();
                this.closeEventForm();
                this.showSaveStatus();
            }

            deleteEvent() {
                if (this.editingEvent && confirm('Are you sure you want to delete this event?')) {
                    const index = this.events[this.selectedDate].findIndex(e => e.id === this.editingEvent.id);
                    if (index !== -1) {
                        this.events[this.selectedDate].splice(index, 1);
                        if (this.events[this.selectedDate].length === 0) {
                            delete this.events[this.selectedDate];
                        }
                    }
                    this.saveEvents();
                    this.render();
                    this.closeEventForm();
                    this.showSaveStatus();
                }
            }

            saveEvents() {
                // In a real environment, you would use localStorage:
                // localStorage.setItem('calendarEvents', JSON.stringify(this.events));
                console.log('Events saved:', this.events);
            }

            loadEvents() {
                // In a real environment, you would use localStorage:
                // const saved = localStorage.getItem('calendarEvents');
                // if (saved) {
                //     this.events = JSON.parse(saved);
                // }
                console.log('Events loaded');
            }

            showSaveStatus() {
                this.saveStatus.classList.add('show');
                setTimeout(() => {
                    this.saveStatus.classList.remove('show');
                }, 2000);
            }
        }

        // Initialize calendar when page loads
        document.addEventListener('DOMContentLoaded', () => {
            new CalendarSchedule();
        });
    </script>
</body>
</html>
